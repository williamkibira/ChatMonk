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

#include "grouphandler.h"

GroupHandler::GroupHandler(Engine* engine)
{
  this->engine = engine;
}
bool GroupHandler::deleteGroup(std::string group_id)
{
  Yb::Session session(Yb::init_schema(), engine);
  Group groupDB = query<Group>(session).filter_by(Group::c.group_id==group_id).one();
  groupDB.delete_object();
  session.commit();
  return true;
}
bool GroupHandler::deleteGroup(Group* group)
{
  Yb::Session session(Yb::init_schema(), engine);
  Group groupDB = query<Group>(session).filter_by(Group::c.group_id==group->group_id).one();
  groupDB.delete_object();
  session.commit();
  return true;
}
DomainResultSet<Group> GroupHandler::getAllGroups()
{
  Yb::Session session(Yb::init_schema(), engine);
  DomainResultSet<Group> groups = query<Group>(session).all();
  
  return groups;
}
DomainResultSet<Group> GroupHandler::getGroupByName(std::string name)
{ 
  Yb::Session session(Yb::init_schema(), engine);
  DomainResultSet<Group> groups = query<Group>(session)
  .filter_by(Group::c.group_name == name && Group::c.activated=="TRUE").all();
  
  return groups;
}
Group GroupHandler::getGroupByID(std::string group_id)
{
  Yb::Session session(Yb::init_schema(), engine);
  Group groupDB = query<Group>(session).filter_by(Group::c.group_id==group_id).one();
  return groupDB;
}
bool GroupHandler::saveGroup(const protobuffer::GroupDef& groupDef)
{
  Yb::Session session(Yb::init_schema(), engine);
  Group::Holder groupDB;
  groupDB->group_name = groupDef.group_name();
  groupDB->group_id = groupDef.group_id();
  groupDB->group_description = groupDef.group_description();
  groupDB->group_photo_uri = groupDef.group_photo_uri();
  groupDB->activated = "TRUE";
  groupDB->save(session);
  session.commit();
  return true;
}

GroupHandler::~GroupHandler()
{
  
}
