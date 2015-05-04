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



#ifndef GROUP_H
#define GROUP_H

#include "friend.h"

using namespace stactiverecord;
using namespace std;

class Group : public Record<Group> {
public:
  SAR_INIT();
Group();
Group(int id):Record<Group>(id){};
~Group();
virtual void save();
virtual void init();
string group_name;
string group_id;
string group_description;
string group_photo_url;
bool activated;
Friend creator;
};
#endif // GROUP_H
SAR_SET_CLASSNAME(Group, "Group");
