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

#ifndef FRIENDCHATWINDOW_H
#define FRIENDCHATWINDOW_H
#include "../datahandlers/datahandler.h"
#include "../broker/friend_message_listener.h"
#include <cdk/cdk.h>

class FriendChatWindow: public FriendMessageListener
{
public:
FriendChatWindow(CDKSREEN *parent);
virtual ~FriendChatWindow();
void appendMessageScroll(std::string message, bool isReply, bool hasAttachment);
void messageFriendReceived(const protobuffer::Message& messageData, size_t messageSize);
protected:
static void onAttach(struct SButton *button);
void onSendPressed();
void onAttachPressed();
void initUI();
private:
  
CDKSCREEN *parent;
CDKBUTTON *sendMsg,*attachFile;
CDKSCREEN *parent;
CDKENTRY *messageEntry;
CDKSWINDOW *messageScroll;
int width, msg_width;
int height, msg_height;
int pos_x;
int pos_y;
std::string message_label, title_label, past_msg_title;
static void* ptr;
MessageHandler *msgHandler;
};

#endif // FRIENDCHATWINDOW_H
