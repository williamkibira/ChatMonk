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


#ifndef NETWORK_HANDLER_H
#define NETWORK_HANDLER_H

#include<curl/curl.h>
#include<curl/easy.h>
#include<curl/curlbuild.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/stat.h>
#include<sstream>
#include<iostream>
#include<list>
#include<ostream>
#include<stdio.h>
#include <fcntl.h>
#include "network_pair.h"
#include"network_callback.h"
using namespace std;
class NetworkHandler{
  
public:
  NetworkHandler();
  virtual ~NetworkHandler();
  void sendParamPost(string url,list<KeyVal> params);
  void sendFilePost(string url, string filepath);
  void postData(string url, string data, string application_type);
  void sendFilePostWithParams(string url, string filepath, list<KeyVal> params);
  int responseCode();
  string getDataReply();
  void updateDataProgress(double TotalToDownload, double NowDownloaded, 
                    double TotalToUpload, double NowUploaded);
  void setNetworkListener(NetworkCBListener *networkListener);
  static int progressFunction(void* ptr, double TotalToDownload, double NowDownloaded, 
                    double TotalToUpload, double NowUploaded); 
  static size_t curl_callback(void *contents, size_t size, size_t nmemb, void *userp);
  CURLcode curl_fetch_url(CURL *ch, const char *url, struct curl_fetch_st *fetch);
  void setData(struct curl_fetch_st *data_load);
private:
  int response_code;
  char *data;
  CURL *curlOBJ;
  struct curl_fetch_st curl_fetch;                        /* curl fetch struct */
  struct curl_fetch_st *cf;                               /* pointer to fetch struct */
  struct curl_slist *headers = NULL;                      /* http headers to send with request */
  struct stat file_info;
  double speed_upload, total_time;
  NetworkCBListener *networkListener;
  bool upload;
  FILE *filePtr;
  struct curl_fetch_st *data_set;

  
};
#endif // NETWORK_HANDLER_H




