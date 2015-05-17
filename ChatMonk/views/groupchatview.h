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

#ifndef GROUPCHATVIEW_H
#define GROUPCHATVIEW_H

#include "../../datahandlers/datahandler.h"
#include "../broker/group_message_listener.h"
#include <cdk/cdk.h>
class GroupChatView:public GroupMessageListener
{
public:
GroupChatView(CDKSCREEN *parent);
virtual ~GroupChatView();
void appendMessageScroll(std::string message, bool isReply, bool hasAttachment);
void messageGroupReceived(const protobuffer::Message& messageData, size_t messageSize);
protected:
  
  static void onAttach(struct SButton *button);
  void onAttachPressed();
void initUI();
private:
GroupHandler *groupHandler;
MessageHandler *MessageHandler;
CDKSCREEN *parent;
CDKSWINDOW grpMessagesWin;
CDKBUTTON *attachFile;
CDKENTRY *messageEntry;
int width, msg_width;
int height, msg_height;
int pos_x;
int pos_y;
std::string message_label, title_label, past_msg_title;
static void* ptr;
MessageHandler *msgHandler;
};

#endif // GROUPCHATVIEW_H
