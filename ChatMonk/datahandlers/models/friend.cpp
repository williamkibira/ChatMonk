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

#include "friend.h"

Friend::Friend()
{

}

void Friend::init()
{
   get("first_name", first_name);
   get("last_name", last_name);
   get("image_url", image_url);
   get("phone_number", phone_number);
   get("email", email);
   get("friend_id", friend_id);
   
}
void Friend::save()
{
    if(!first_name.empty() && !friend_id.empty()){
      set("first_name", first_name);
      set("last_name", last_name);
      set("image_url", image_url);
      set("phone_number", phone_number);
      set("email", email);
      set("friend_id", friend_id);
      Record<Friend>::save();
    }else{
      cout<<"Error ! Invalid Friend Object"<<endl;
    }
}

Friend::~Friend()
{

}
