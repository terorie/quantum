/*
** Copyright 2021 Bloomberg Finance L.P.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/
//NOTE: DO NOT INCLUDE DIRECTLY

//##############################################################################################
//#################################### IMPLEMENTATIONS #########################################
//##############################################################################################

#include <quantum/util/quantum_sequence_key_statistics.h>
#include <quantum/interface/quantum_icoro_context_base.h>

namespace Bloomberg {
namespace quantum {

using StatsPtr = std::shared_ptr<SequenceKeyStatisticsWriter>;
struct SequenceKeyData
{
    SequenceKeyData() :
        _stats(std::make_shared<SequenceKeyStatisticsWriter>())
    {}
    ICoroContextBasePtr _context;
    StatsPtr            _stats;
};

inline const std::string&
SequencerConfigurationSchemaProvider::getJsonSchema()
{
    static std::string schema = R"JSON(
    {
        "$schema" : "http://json-schema.org/draft-04/schema#",
        "$id" : "bloomberg:sequencer.quantum.json",
        "title": "Quantum sequencer settings",
        "type": "object",
        "properties": {
            "controlQueueId": {
                "type": "number",
                "default": 0
            },
            "bucketCount": {
                "type": "number",
                "default": 100
            }
        },
        "additionalProperties": false,
        "required": []
    }
    )JSON";
    return schema;
}

inline const std::string&
SequencerConfigurationSchemaProvider::getJsonSchemaUri()
{
    static std::string uri = "bloomberg:sequencer.quantum.json";
    return uri;
}

template <class SequenceKey, class Hash, class KeyEqual, class Allocator>
SequencerConfiguration<SequenceKey, Hash, KeyEqual, Allocator>&
SequencerConfiguration<SequenceKey, Hash, KeyEqual, Allocator>::setControlQueueId(int controlQueueId)
{
    _controllerQueueId = controlQueueId;
    return *this;
}

template <class SequenceKey, class Hash, class KeyEqual, class Allocator>
int
SequencerConfiguration<SequenceKey, Hash, KeyEqual, Allocator>::getControlQueueId() const
{
    return _controllerQueueId;
}

}}
