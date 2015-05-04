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

#include "invitation.h"

Invitation::Invitation()
{

}

void Invitation::init()
{
    get("unique_id",unique_id);
    get("private_message", private_message);
    //getOne<Group>(group);
}

void Invitation::save()
{
  if(!unique_id.empty()){
     set("unique_id",unique_id);
     set("private_message", private_message);
     //setOne<Group>(group);
     Record<Invitation>::save();
    cout <<"Data has been saved"<<endl; 
  }else{
    cout<<"You have not set all the fields"<<endl;
  }
}

Invitation::~Invitation()
{

}
