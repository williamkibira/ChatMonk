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

#include "messagehandler.h"

MessageHandler::MessageHandler()
{
  datahandler = DataHandler::getInstance();
  Sar_Dbi::dbi = datahandler->getDBSar();
}
bool MessageHandler::deleteConversation(string friend_id)
{
  ObjGroup<ChatMessage> messages = ChatMessage::find(Q("sender_id",friend_id) || Q("receiver_id",friend_id));
  for(int i = 0; i < messages.size(); ++i){
    messages.at(i).del();
  }
  return true;
}
bool MessageHandler::deleteMessage(ChatMessage* message)
{
  ChatMessage chatMessage;
  chatMessage.get("id",message->id);
  chatMessage.del();
  return true;
}
std::list< ChatMessage > MessageHandler::getAllMessages()
{
  std::list<ChatMessage> messages;
  ObjGroup<ChatMessage> messagesDB = ChatMessage::all();
  for(int i = 0; i < messagesDB.size(); ++i){
    messages.push_back(messagesDB.at(i));
  }
  return messages;
}
std::list< ChatMessage > MessageHandler::getMessages(string friend_id)
{
  std::list<ChatMessage> messages;
  ObjGroup<ChatMessage> messagesDB = ChatMessage::find(Q("sender_id",friend_id) || Q("receiver_id",friend_id));
  for(int i = 0; i < messagesDB.size(); ++i){
    messages.push_back(messagesDB.at(i));
  }
  return messages;
}
bool MessageHandler::saveMessage(protobuffer::Message* message)
{
  ChatMessage chatMessage;
  chatMessage.message_data = message->message_data();
  if(message->messagetype()== protobuffer::Message::FRND_MSG){
    chatMessage.msgType = MSG_TYPE::FRIEND_MSG;
  }else{
    chatMessage.msgType = MSG_TYPE::GROUP_MSG;
  }
  chatMessage.receiver_id = message->receiver_id();
  chatMessage.sender_id = message->sender_id();
  chatMessage.save();
}

MessageHandler::~MessageHandler()
{
  delete Sar_Dbi::dbi;
}
