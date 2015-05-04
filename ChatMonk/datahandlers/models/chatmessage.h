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




#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include <stactiverecord/stactive_record.h>
#include <string>
#include <list>

using namespace stactiverecord;
using namespace std;
enum MSG_TYPE{ FRIEND_MSG, GROUP_MSG};
class ChatMessage: public Record<ChatMessage>{
public:
  SAR_INIT();
ChatMessage();
ChatMessage(int id):Record<ChatMessage>(id){};
~ChatMessage();
virtual void save();
virtual void init();

string message_data;
string sender_id;
string receiver_id;
std::list<string> attachments;
MSG_TYPE msgType;
};
#endif // CHATMESSAGE_H
SAR_SET_CLASSNAME(ChatMessage, "ChatMessage");