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

GroupHandler::GroupHandler()
{
  datahandler = DataHandler::getInstance();
  Sar_Dbi::dbi = datahandler->getDBSar();
}
bool GroupHandler::deleteGroup(string group_id)
{
  Group groupDB;
  groupDB.get("group_id",group_id);
  
  groupDB.del();
  return true;
}
bool GroupHandler::deleteGroup(Group* group)
{
  Group groupDB;
  groupDB.get("group_id", group->group_id);
  groupDB.del();
  return true;
}
std::list< Group > GroupHandler::getAllGroups()
{
  std::list<Group> groups;
  ObjGroup<Group> groupsDB = Group::all();
  for(int i = 0; i < groupsDB.size(); ++i){
    groups.push_back(groupsDB.at(i));
  }
  return groups;
}
std::list< Group > GroupHandler::getGroupByName(string name)
{ 
  std::list<Group> groups;
  ObjGroup<Group> groupsDB = Group::find(Q("name",name) && Q("activated", true));
  for(int i = 0; i < groupsDB.size(); ++i){
    groups.push_back(groupsDB.at(i));
  }
  return groups;
}
Group GroupHandler::getGroupByID(string group_id)
{
  Group groupDB;
  groupDB.get("group_id", group_id);
  return groupDB;
}
bool GroupHandler::saveGroup(protobuffer::GroupDef* groupDef)
{
  Group groupDB;
  groupDB.group_name = groupDef->group_name();
  groupDB.group_id = groupDef->group_id();
  groupDB.group_description = groupDef->group_description();
  groupDB.group_photo_url = groupDef->group_photo_uri();
  groupDB.activated = true;
  groupDB.save();
  return groupDB.has_been_saved();
}

GroupHandler::~GroupHandler()
{
  delete Sar_Dbi::dbi;
}
