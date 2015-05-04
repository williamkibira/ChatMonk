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
#include "models/chatmessage.h"
#include "models/group.h"
#include "models/friend.h"
#include "models/invitation.h"
#include <stactiverecord/stactive_record.h>

using namespace stactiverecord;
class DataHandler
{
public:


~DataHandler();
DataHandler *getInstance();
Sar_Dbi * getDBSar();
private:
DataHandler();
private:
static DataHandler* _dbHandler;
Sar_Dbi * Sar_Dbi::dbi;
std::string configDB;
};

#endif // DATAHANDLER_H
