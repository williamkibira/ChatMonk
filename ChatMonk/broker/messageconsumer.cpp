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

#include "messageconsumer.h"
void* MessageConsumer::ptr = NULL;
MessageConsumer::MessageConsumer()
{
  counter = 0;
  MessageConsumer::ptr =  this;
}

MessageConsumer::MessageConsumer(std::list<std::string>& routing_keys)
{
  counter = 0;
  this->routing_keys = routing_keys;
  MessageConsumer::ptr =  this;
}


MessageConsumer::~MessageConsumer()
{

}
void MessageConsumer::addKeyToQueue(string routing_key)
{
      queue->Bind( QUEUE_NAME, routing_key);
}
void MessageConsumer::startConsumer()
{
    consumerRun = true;
    runMessageConsumer();
}
void MessageConsumer::stopConsumer()
{
    consumerRun = false;
    queue->Cancel(CONSUMER_TAG);
}

void MessageConsumer::runMessageConsumer()
{
          try {
		AMQP amqp(HOST);

		queue = amqp.createQueue("q2");

		queue->Declare();
		
		if(!routing_keys.empty()){
		for(std::list<string>::iterator iter = routing_keys.begin(); iter != routing_keys.end(); ++iter){
		  queue->Bind(QUEUE_NAME, (*iter));
		}
		  
		}

		queue->setConsumerTag(CONSUMER_TAG);
		queue->addEvent(AMQP_MESSAGE, MessageConsumer::onMessageReceived);
		queue->addEvent(AMQP_CANCEL, MessageConsumer::onMessageCancelled);


	} catch (AMQPException e) {
		std::cout << e.getMessage() << std::endl;
	}

	queue->Consume(AMQP_NOACK);     
}

void MessageConsumer::setFriendMessageListener(FriendMessageListener* friendMessageListener)
{
  this->friendMessageListener = friendMessageListener;
}
void MessageConsumer::setGroupMessageListener(GroupMessageListener* groupMessageListener)
{
  this->groupMessageListener = groupMessageListener;
}
void MessageConsumer::setInvitationMessageListener(InvitationMessageHandler* invitationMessageHandler)
{
  this->invitationMessageHandler = invitationMessageHandler;
}

int MessageConsumer::onMessageCancelled(AMQPMessage * message)
{
    std::cout << "cancel tag="<< message->getDeliveryTag() << std::endl;
	return 0;
}
int MessageConsumer::onMessageReceived(AMQPMessage * message)
{
	uint32_t j = 0;
	std::string data = std::string(message->getMessage(&j));
	if (!data.empty())
		  std::cout << data << std::endl;
	          try{
	          protobuffer::Message message;
		  message.ParseFromString(data);
	          if(message.messagetype()==protobuffer::Message::FRND_MSG){
		     static_cast<MessageConsumer*>(MessageConsumer::ptr)->friendMessageListener->messageFriendReceived(message,message.ByteSize());
		  }
		  else{
		     static_cast<MessageConsumer*>(MessageConsumer::ptr)->groupMessageListener->messageGroupReceived(message,message.ByteSize());
		  }
		  }catch(google::protobuf::exception e){
		    std::cout<<" Wrong Format"<< e.what() <<std::endl;
		        static_cast<MessageConsumer*>(MessageConsumer::ptr)->parseInvitation(data);
		  }
	
	return 0;
}
void MessageConsumer::parseInvitation(const string& data)
{
   try{
    
		    std::cout<<"Attempt Read as an invitation"<<std::endl;
		    protobuffer::InvitationDef invitation;
		    invitation.ParseFromString(data); 
		    invitationMessageHandler->invitationMessageReceived(invitation,invitation.ByteSize());
  }catch(google::protobuf::exception e){
         std::cout<< e.what()<<std::endl;
	 std::cout<<"Failed to parse the strings data"<<std::endl;
  }
}

