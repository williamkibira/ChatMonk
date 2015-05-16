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

#ifndef GROUPLISTVIEW_H
#define GROUPLISTVIEW_H
#include <cdk/cdk.h>
#include <list>
#include <boost/foreach.hpp>
class GroupListView
{
public:
GroupListView(CDKSCREEN *parent);
virtual ~GroupListView();
protected:
void sendMessage(struct SButton *button);
void addAttachment(struct SButton *button);
std::string fileSelectorDialog();
private:
CDKSCREEN *parent;
std::list<Group> groups;
CDKSCROLL *listScroll;

int width;
int height;
  
};

#endif // GROUPLISTVIEW_H
