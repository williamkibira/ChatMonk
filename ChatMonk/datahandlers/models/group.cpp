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

#include "group.h"



Group::Group()
{

}

void Group::save()
{
 if(!group_name.empty()){
     set("group_name",group_name);
     set("group_description",group_description);
     set("group_photo_url", group_photo_url);
     set("group_id",group_id);
     set("activated",activated);
     setOne<Friend>(creator);
     Record<Group>::save();
}else{
  cout<<"Group Details no set"<<endl;
}

}

void Group::init()
{
  get("group_name",group_name);
  get("group_description", group_description);
  get("group_photo_url", group_photo_url);
  get("group_id", group_id);
  getOne<Friend>(creator);
}


Group::~Group()
{

}
