/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Modified by Cloudius Systems
 * Copyright 2015 Cloudius Systems
 */

#pragma once

#include "core/sstring.hh"
#include "utils/UUID.hh"

namespace db {

// FIXME: real ColumnFamily
class ColumnFamily;

class i_mutation {
public:
    virtual ~i_mutation() {};
    virtual sstring get_keyspace_name() =0;
    virtual std::vector<utils::UUID> get_column_family_ids() = 0;
    virtual bytes key() = 0;
    virtual int64_t get_timeout() = 0;
    virtual sstring to_string(bool shallow) = 0;
    virtual void add_all(i_mutation& m) = 0;
    virtual std::vector<ColumnFamily> get_column_families() = 0;
};

}
