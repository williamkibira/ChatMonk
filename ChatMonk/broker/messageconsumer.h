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

#define QUEUE_NAME "CHAT_MONK_QUEUE"
#define HOST "178.62.202.9"
#define CONSUMER_TAG "tag_CHAT_MONK"

#include <amqpcpp/AMQPcpp.h>
#include <stdio.h>
#include <iostream>
#include "friend_message_listener.h"
#include "invitation_message_listener.h"
#include "group_message_listener.h"
#include "../protobuffer/chat_monk.pb.h"
#include <list>
#ifndef MESSAGECONSUMER_H
#define MESSAGECONSUMER_H


class MessageConsumer
{
public:
MessageConsumer();  
MessageConsumer(std::list<std::string>& routing_keys);
~MessageConsumer();

static int onMessageReceived(AMQPMessage *message);
static int onMessageCancelled(AMQPMessage * message);
void addKeyToQueue(std::string routing_key);
void parseInvitation(const std::string& data);
void startConsumer();
void stopConsumer();
void setGroupMessageListener(GroupMessageListener *groupMessageListener);
void setFriendMessageListener(FriendMessageListener *friendMessageListener);
void setInvitationMessageListener(InvitationMessageHandler *invitationMessageHandler);
private:
  void runMessageConsumer();
  AMQPQueue *queue;
  int counter;
  bool consumerRun;
  GroupMessageListener *groupMessageListener;
  FriendMessageListener *friendMessageListener;
  InvitationMessageHandler *invitationMessageHandler;
  std::list<std::string> routing_keys;
  static void* ptr;
};

#endif // MESSAGECONSUMER_H
