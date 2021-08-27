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
#include <list>
#include <vector>
#include <atomic>
#include <memory>

namespace Bloomberg {
namespace quantum {

inline const std::string&
SequencerLiteConfigurationSchemaProvider::getJsonSchema()
{
    static std::string schema = R"JSON(
    {
        "$schema" : "http://json-schema.org/draft-04/schema#",
        "$id" : "bloomberg:sequencerlite.quantum.json",
        "title": "Quantum sequencerlite settings",
        "type": "object",
        "properties": {
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
SequencerLiteConfigurationSchemaProvider::getJsonSchemaUri()
{
    static std::string uri = "bloomberg:sequencerlite.quantum.json";
    return uri;
}

}}
