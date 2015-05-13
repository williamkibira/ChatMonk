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
DataHandler* DataHandler::_dbHandler = NULL;

DataHandler::DataHandler()
{
  try{
     std::auto_ptr<Yb::SqlConnection> conn(new Yb::SqlConnection(
            "sqlite+sqlite://./CHAT_MONK.dp"));
    Yb::Engine engine(Yb::Engine::READ_WRITE, conn);
    Yb::Session session(Yb::init_schema(), &engine);
    // Initialize all the Handlers at one and keep the at bay
    inviHandler = new InvitationHandler(session);
    msgHandler = new MessageHandler(session);
    frndHandler = new FriendHandler(session);
    grpHandler = new GroupHandler(session);
    }catch(exception &e){
      printf("%sException Caught %s%s\n",RED,e->what().c_str(),RESET);
    }
}
DataHandler* DataHandler::getInstance()
{
  if(_dbHandler == NULL){
    _dbHandler = new DataHandler();
    printf("%s The Database Instance has been created %s\n",GREEN,RESET);
  }
  return _dbHandler;
}

GroupHandler* DataHandler::getGroupHandlerInst()
{ 
  if(grpHandler == NULL)
  {
    _dbHandler = new DataHandler();
  }
  return grpHandler;
}
FriendHandler* DataHandler::getFriendHandlerInst()
{     
  if(frndHandler == NULL)
  {
    _dbHandler = new DataHandler();
  }
      return frndHandler;
}
MessageHandler* DataHandler::getMessageHandlerInst()
{     
  if(msgHandler == NULL)
  {
    _dbHandler = new DataHandler();
  }
      return msgHandler;
}
InvitationHandler* DataHandler::getInvitationHandlerInst()
{     
  if(inviHandler == NULL)
  {
    _dbHandler = new DataHandler();
  }
      return inviHandler;
}

DataHandler::~DataHandler()
{
      delete invHandler;
      delete msgHandler;
      delete frndHandler;
      delete grpHandler;
      delete _dbHandler; 
}
