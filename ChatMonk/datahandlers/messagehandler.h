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

#include "models/ChatMessageDB.h"
#include "../protobuffer/chat_monk.pb.h"
#include <string>

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#define GROUP_MESSAGE "GROUP_MESSAGE"
#define FRIEND_MESSAGE "FRIEND_MESSAGE"
using namespace Yb;
using namespace Domain::Holder;

class MessageHandler
{
public:
MessageHandler(const Session& session);
~MessageHandler();
bool saveMessage(const protobuffer::Message& message);
DomainResultSet<ChatMessageDB> getMessages(std::string friend_id);
DomainResultSet<ChatMessageDB> getAllMessages();
bool deleteConversation(std::string friend_id);
bool deleteMessage(ChatMessageDB *message);
private:
Session session;
};

#endif // MESSAGEHANDLER_H
