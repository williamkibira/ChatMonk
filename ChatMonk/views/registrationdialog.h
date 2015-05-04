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
#include <cdk/cdk.h>

class RegistrationDialog
{
public:
RegistrationDialog(CDKSCREEN *screen);
~RegistrationDialog();

private:
CDKTEMPLATE *regTemplate;
// Labels
char * first_name_label;
char * last_name_label;
char * phone_number_label;
char * email;
char * photo_path_label;
// Entries
char * first_name_entry;
char * last_name_entry;
char * phone_number_entry;
char * email_entry;
char * photo_path_entry;

};

#endif // REGISTRATIONDIALOG_H
