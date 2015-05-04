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
  
}
DataHandler* DataHandler::getInstance()
{
  if(_dbHandler != NULL){
    _dbHandler = new DataHandler();
  }
}
Sar_Dbi* DataHandler::getDBSar()
{
  if(Sar_Dbi::dbi == NULL){
    Sar_Dbi::dbi = Sar_Dbi::makeStorage(std::string(configDB));
  }
  return Sar_Dbi::dbi;
}


DataHandler::~DataHandler()
{
  delete Sar_Dbi::dbi;
}
