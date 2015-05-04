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

#include "datahandler.h"
#include "models/chatmessage.h"
#include "../protobuffer/chat_monk.pb.h"
#include <list>
#include <string>

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

class MessageHandler
{
public:
MessageHandler();
~MessageHandler();
bool saveMessage(protobuffer::Message *message);
std::list<ChatMessage> getMessages(std::string friend_id);
std::list<ChatMessage> getAllMessages();
bool deleteConversation(std::string friend_id);
bool deleteMessage(ChatMessage *message);
private:
DataHandler *datahandler;
Sar_Dbi *Sar_Dbi::dbi;
};

#endif // MESSAGEHANDLER_H
