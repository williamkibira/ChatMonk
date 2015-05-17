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

#include "groupchatview.h"

GroupChatView::GroupChatView(CDKSCREEN *parent)
{
  GroupChatView::ptr = this;
  this->parent = parent;
  msgHandler = DataHandler::getInstance()->getMessageHandlerInst();
  pos_x = parent->window->_begx;
  pos_y = parent->window->_begy;
  msg_height = parent->window->_begx + 360;
  msg_width = parent->window->_begy + 480;
}
void GroupChatView::appendMessageScroll(std::string message, bool isReply, bool hasAttachment)
{
    std::string message_format;
    if(isReply){
        
	message_format = "<L></11>:"<< message <<".";
    }else{
	message_format = "<R></11>:"<< message <<".";   
    }
    if(hasAttachment){
        message_format.append<std::string>("</K/31>HAS ATCH<!31>"); // blue blinking text
    }
        addCDKSwindow (grpMessagesWin, message_format.c_str(), BOTTOM);
}
void GroupChatView::initUI()
{
      // Set Up the Entry For the Verbose Input
     
     grpMessagesWin = newCDKSwindow(parent,pos_x, pos_y, msg_height,msg_width,past_msg_title.c_str(),100,
                      true,false);
     
     messageEntry = newCDKEntry(parent,pos_x,grpMessagesWin->boxHeight + 5 + pos_y,message_label.c_str(),title_label.c_str(),
                               A_BOLD, '.', vMIXED,grpMessagesWin->boxWidth - 8,5,20,true,false);
     
     attachFile = newCDKButton(parent,messageEntry->boxWidth + pos_x + 2,pos_y,"Attach File", GroupChatView::onAttach,
                      true,true);   
     activateCDKSwindow (grpMessagesWin, 0);
     activateCDKEntry(messageEntry,0);
     activateCDKButton(attachFile,0);
}
void GroupChatView::messageGroupReceived(const protobuffer::Message& messageData, size_t messageSize)
{
     bool hasAttachment = false;
	  msgHandler->saveMessage(messageData);  
     if(messageData.attachments_size() > 0){
	hasAttachment = true;
     } 
    appendMessageScroll(messageData.message_data(),true,hasAttachment);
}
void GroupChatView::onAttach(SButton* button)
{
     static_cast<GroupChatView*>(ptr)->onAttachPressed();
}
void GroupChatView::onAttachPressed()
{
     
}

GroupChatView::~GroupChatView()
{

}
