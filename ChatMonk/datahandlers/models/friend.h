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



#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <string>
#include <stactiverecord/stactive_record.h>

using namespace stactiverecord;
using namespace std;
class Friend : public Record<Friend>{
      
public:
  SAR_INIT();
Friend();
Friend(int id):Record<Friend>(id){};
virtual ~Friend();
virtual void save();
virtual void init();
        string first_name;
	string last_name;
	string friend_id;
	string phone_number;
	string email;
	string image_url;
};
#endif // FRIEND_H
SAR_SET_CLASSNAME(Friend, "Friend");