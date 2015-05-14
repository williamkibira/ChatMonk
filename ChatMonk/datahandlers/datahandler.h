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

#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include "messagehandler.h"
#include "friendhandler.h"
#include "grouphandler.h"
#include "invitationhandler.h"
#include "../views/colors.h"
#include <string.h>
#include <stdio.h>
#define DB_NAME "CHAT_MONK.ds"
#define DB_TYPE "sqlite"



class DataHandler
{
public:

virtual ~DataHandler();
DataHandler *getInstance();

private:
DataHandler();

GroupHandler* getGroupHandlerInst();
FriendHandler* getFriendHandlerInst();
MessageHandler* getMessageHandlerInst();
InvitationHandler* getInvitationHandlerInst();


private:
static DataHandler* _dbHandler;
GroupHandler *grpHandler;
FriendHandler *frndHandler;
InvitationHandler *inviHandler;
MessageHandler *msgHandler;

};

#endif // DATAHANDLER_H
