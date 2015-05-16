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


MessageHandler::MessageHandler(Engine* engine)
{
    this->engine = engine;
}
bool MessageHandler::deleteConversation(std::string friend_id)
{
  Yb::Session session(Yb::init_schema(), engine);
  DomainResultSet<ChatMessageDB> messages = query<ChatMessageDB>(session)
  .filter_by(ChatMessageDB::c.receiver_id==friend_id || ChatMessageDB::c.sender_id==friend_id).all();
  BOOST_FOREACH(ChatMessageDB msg, messages){
    msg.delete_object();
    session.commit();
  }
  return true;
}
bool MessageHandler::deleteMessage(ChatMessageDB* mesg)
{
  Yb::Session session(Yb::init_schema(), engine);
  ChatMessageDB chatmessage = query<ChatMessageDB>(session).filter_by(ChatMessageDB::c.id==mesg->id).one();
  // Then we figure out a way to delete the darn stuff man
  chatmessage.delete_object();
  session.commit();
  return true;
}
DomainResultSet<ChatMessageDB> MessageHandler::getAllMessages()
{
  Yb::Session session(Yb::init_schema(), engine);
  DomainResultSet<ChatMessageDB> messages = query<ChatMessageDB>(session)
  .all();
  return messages;
}
DomainResultSet<ChatMessageDB> MessageHandler::getMessages(std::string friend_id)
{
  Yb::Session session(Yb::init_schema(), engine);
  DomainResultSet<ChatMessageDB> messages = query<ChatMessageDB>(session)
  .filter_by(ChatMessageDB::c.sender_id==friend_id || ChatMessageDB::c.receiver_id==friend_id).all();
  return messages;
}
bool MessageHandler::saveMessage(const protobuffer::Message& message)
{
  Yb::Session session(Yb::init_schema(), engine);
  ChatMessageDB::Holder chatMessage(session);
  chatMessage->message_data = message.message_data();
  if(message.messagetype()== protobuffer::Message::FRND_MSG){
    //chatMessage = FRIEND_MESSAGE;
  }else{
    //chatMessage->message_type = GROUP_MESSAGE;
  }
  chatMessage->receiver_id = message.receiver_id();
  chatMessage->sender_id = message.sender_id();
  chatMessage->save(session);
  if(message.attachments_size() > 0){
    for(int i = 0; i < message.attachments_size(); ++i){
      
      AttachmentDB::Holder attachment;
      const protobuffer::Attachment& att = message.attachments(i);
      attachment->attachment_uri = att.server_file_path();
      attachment->message = chatMessage;
      attachment->save(session);
    }
  }
  session.commit();
  return true;

}

MessageHandler::~MessageHandler()
{
  
}
