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

#include "registrationdialog.h"

RegistrationDialog::RegistrationDialog()
{
   networkHandler = new NetworkHandler();
   networkHandler->setNetworkListener(this);
   
}

bool RegistrationDialog::takeInDetails(){
	printf(" %s Enter Your First Name %s\n",LIGHT_GRAY,RESET);
	std::cin<<first_name_entry<<std::endl;
	printf(" %s Enter Your Last Name %s\n",LIGHT_GRAY,RESET);
	std::cin<<last_name_entry<<std::endl;
	printf(" %s Enter Your Phone Number %s\n",YELLOW,RESET);
	std::cin<<phone_number_entry<<std::endl;
	printf(" %s Enter Your Email Entry %s\n",RED,RESET);
	std::cin<<email_entry<<std::endl;
	printf(" %s Photo Path %s\n",LIGHT_GRAY,RESET);
	std::cin<<photo_path_entry<<std::endl;
    if(!verifyDetails()){
		printf(" %s Invalid Details Entered %s\n",RED,RESET);
	    return takeInDetails();
	}else{
		return true;
	}
}
 void RegistrationDialog::cbiNetworkStatus(std::string message, int status_code){
	  if(status_code != 200){
		 printf(" %s Major League F**k Up %s  %d\n", RED, RESET, status_code);
		 printf("%s Error Message %s %s\n", YELLOW, message.c_str(),RESET); 
	  }else{
		 printf("%s%s %s%d %s\n", GREEN, message,MAGENTA,status_code,RESET); 
	  }
 }
 void RegistrationDialog::cbiProgressLevel(std::string message, double sent, double total){
	  printf("%s%s %s%d %s%d %s\n", GREEN,message.c_str(), YELLOW,sent, BLUE,total, RESET);
  }
void RegistrationDialog::sendDetails(){
	 protobuffer::RegistrationPack pack;
	 pack.first_name = first_name_entry;
	 pack.last_name = last_name_entry;
	 pack.phone_number = phone_number_entry;
	 pack.email = email_entry;
	 pack.photo = "";
	 std::string data;
	 pack.SerializeToString(&data);
	 networkHandler->postData(REGISTRATION_URL, data, "application/x-protobuf");
}
void RegistrationDialog::saveDataToDB(){
	 std::string reply_data = networkHandler->getDataReply();
	 protobuffer::FriendDef friendDef;
	 friendDef.ParseFromString(&reply_data);
	 
}
bool RegistrationDialog::verifyDetails(){
bool isInvalid = false;
if(first_name_entry.empty()||last_name_entry.empty()){
   	isInvalid = true;
}
if(phone_number_entry.empty()){
	isInvalid = true;
}	
	return isInvalid;
}

RegistrationDialog::~RegistrationDialog()
{

}
