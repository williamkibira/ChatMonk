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

#include "chatmessage.h"

ChatMessage::ChatMessage()
{

}


void ChatMessage::init()
{
  get("message_data",message_data);
  get("sender_id", sender_id);
  get("receiver_id", receiver_id);
}
void ChatMessage::save()
{
  if(!message_data.empty() || !sender_id.empty()){
    set("message_data", message_data);
    set("sender_id",sender_id);
    set("receiver_id",receiver_id);
    Record<ChatMessage>::save();
  }
}

ChatMessage::~ChatMessage()
{

}
