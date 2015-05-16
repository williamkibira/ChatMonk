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

#ifndef FRIENDLISTVIEW_H
#define FRIENDLISTVIEW_H
#include <list>
#include <cdk/cdk.h>


class FriendListView
{
public:
FriendListView(CDKSCREEN *parent);
virtual ~FriendListView();
private:
CDKSCREEN *parent;
CDKSCROLL *friendList;
int width,height;
int position_x,position_y;

  
};

#endif // FRIENDLISTVIEW_H
