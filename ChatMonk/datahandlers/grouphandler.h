/*
 * Copyright 2015 <copyright holder> <email>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */


#include "models/Group.h"
#include "../protobuffer/chat_monk.pb.h"
#include <string>

#ifndef GROUPHANDLER_H
#define GROUPHANDLER_H
using namespace Yb;
using namespace Domain::Holder;
class GroupHandler
{
public:
GroupHandler(const Session& session);
~GroupHandler();
bool saveGroup(const protobuffer::GroupDef& groupDef);
bool deleteGroup(Group *group);
bool deleteGroup(std::string group_id);
DomainResultSet<Group> getAllGroups();
DomainResultSet<Group> getGroupByName(std::string name);
Group getGroupByID(std::string group_id);
private:
Session session;
};

#endif // GROUPHANDLER_H
