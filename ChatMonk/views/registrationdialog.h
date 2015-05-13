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

#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H

#include "reg_data.h"
#include "../network_handler/networkhandler.h"
#include "../protobuffer/chat_monk.pb.h"
#include "colors.h"
#include <stdio.h>

#define REGISTRATION_URL ""

class RegistrationDialog: public NetworkCBListener{
public:
RegistrationDialog();
virtual ~RegistrationDialog();

bool takeInDetails();
bool verifyDetails();

void sendDetails();
void saveDataToDB();
void cbiNetworkStatus(std::string message, int status_code);
void cbiProgressLevel(std::string message, double sent, double total);
private:
// Labels

std::string first_name_entry;
std::string last_name_entry;
std::string phone_number_entry;
std::string email_entry;
std::string photo_path_entry;
NetworkHandler *networkHandler;

};

#endif // REGISTRATIONDIALOG_H
