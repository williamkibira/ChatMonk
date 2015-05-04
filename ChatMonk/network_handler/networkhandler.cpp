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

#include "networkhandler.h"

NetworkHandler::NetworkHandler(){
 if ((curlOBJ = curl_easy_init()) == NULL) {
        /* log error */
        fprintf(stderr, "ERROR: Failed to create curl handle in fetch_session");
        /* return error */
        
    }
    cf = &curl_fetch;
}
NetworkHandler::~NetworkHandler(){
   curl_easy_cleanup(curlOBJ);
}

void NetworkHandler::sendParamPost(string url,list<KeyVal> params){
    ostringstream stream;
    for(list<KeyVal>::iterator iter= params.begin(); iter != params.end(); ++iter){
	KeyVal data = (*iter);
      	
      if(distance(params.begin(),iter)==0){
	 
	      stream<<url<<"?"<<data.key<<"="<<data.value;
	}else{
	      stream<<"&"<<data.key<<"="<<data.value;
	} 
     }
     string my_params = stream.str();
     std::cout<<my_params<<std::endl;
     
     curl_easy_setopt(curlOBJ,CURLOPT_CUSTOMREQUEST,"POST");
     curl_easy_setopt(curlOBJ,CURLOPT_CONNECTTIMEOUT,10);
     //curl_easy_setopt(curlOBJ,CURLOPT_POSTFIELDS,my_params.c_str());
     response_code = curl_fetch_url(curlOBJ,my_params.c_str(), cf); 
     data = cf->payload;
	   printf("DATA %s \n", cf->payload);
     
       networkListener->cbiNetworkStatus("NETWORK PARAMS", response_code); 
    
     
  }
  
  
void NetworkHandler::sendFilePost(string url, string filepath){
    
    if((filePtr=fopen(filepath.c_str(),"rb"))!=NULL){
       fstat(fileno(filePtr), &file_info); // Get the file Size

   
       curl_easy_setopt(curlOBJ, CURLOPT_URL,url.c_str());
       curl_easy_setopt(curlOBJ, CURLOPT_UPLOAD, 1L);
       curl_easy_setopt(curlOBJ, CURLOPT_READDATA, filePtr);
       curl_easy_setopt(curlOBJ, CURLOPT_NOPROGRESS, 0);
      // Install the callback function
       curl_easy_setopt(curlOBJ, CURLOPT_PROGRESSFUNCTION,NetworkHandler::progressFunction);
       curl_easy_setopt(curlOBJ, CURLOPT_INFILESIZE_LARGE,
                     (curl_off_t)file_info.st_size);

    /* enable verbose for easier tracing */
    curl_easy_setopt(curlOBJ, CURLOPT_VERBOSE, 1L);

    response_code = curl_easy_perform(curlOBJ);
    if(response_code != CURLE_OK){
         
     }else{
       
    
    /* now extract transfer info */
      curl_easy_getinfo(curlOBJ, CURLINFO_SPEED_UPLOAD, &speed_upload);
      curl_easy_getinfo(curlOBJ, CURLINFO_TOTAL_TIME, &total_time);

      fprintf(stderr, "Speed: %.3f bytes/sec during %.3f seconds\n",
              speed_upload, total_time);
      
    }
    }
  }
void NetworkHandler::postData(string url, string data, string application_type){
	if(!url.empty() && !data.empty() && !application_type.empty()){
	    string type_1 = "Accept: application/";
	    type_1 += application_type;
	    string type_2 = "Content-Type: application/";
	           type_2 += application_type;
	    headers = curl_slist_append(headers,type_1.c_str());
            headers = curl_slist_append(headers,type_2.c_str());
            curl_easy_setopt(curlOBJ,CURLOPT_CUSTOMREQUEST,"POST");
	    curl_easy_setopt(curlOBJ,CURLOPT_CONNECTTIMEOUT,10);
	    curl_easy_setopt(curlOBJ,CURLOPT_HTTPHEADER,headers);
	    curl_easy_setopt(curlOBJ,CURLOPT_POSTFIELDS,data.c_str());
	    response_code = curl_fetch_url(curlOBJ, url.c_str(), cf);
	    data = cf->payload;
	    printf("DATA %s \n", cf->payload);
	    networkListener->cbiNetworkStatus("NETWORK OK", response_code);
              
	}else{
	    response_code = 500; 
	    
	    networkListener->cbiNetworkStatus("INVALID PARAMETERS", response_code); 
	}
  }
string NetworkHandler::getDataReply(){
       //string payload(data);
    return string(cf->payload);
}  
  
void NetworkHandler::setNetworkListener(NetworkCBListener *networkListener){
     this->networkListener = networkListener;
}
  
void NetworkHandler::sendFilePostWithParams(string url, string filepath, list<KeyVal> params){
     ostringstream stream;
     
     for(list<KeyVal>::iterator iter= params.begin(); iter != params.end(); ++iter){
        KeyVal data = (*iter);
	
	if(distance(params.begin(),iter)==0){
	      stream<<"?"<<data.key<<"="<<data.value;
	}else{
	      stream<<"&"<<data.key<<"="<<data.value;
	}
     }
     if((filePtr=fopen(filepath.c_str(),"rb"))!=NULL){
       fstat(fileno(filePtr), &file_info); // Get the file Size

       string my_params = stream.str();
       curl_easy_setopt(curlOBJ, CURLOPT_URL,url.c_str());
       curl_easy_setopt(curlOBJ,CURLOPT_POSTFIELDS,my_params.c_str());
       curl_easy_setopt(curlOBJ, CURLOPT_UPLOAD, 1L);
       curl_easy_setopt(curlOBJ, CURLOPT_READDATA, filePtr);
       curl_easy_setopt(curlOBJ, CURLOPT_NOPROGRESS, 0);
      // Install the callback function
       curl_easy_setopt(curlOBJ, CURLOPT_PROGRESSFUNCTION,NetworkHandler::progressFunction);
       curl_easy_setopt(curlOBJ, CURLOPT_INFILESIZE_LARGE,
                     (curl_off_t)file_info.st_size);
    /* enable verbose for easier tracing */
    curl_easy_setopt(curlOBJ, CURLOPT_VERBOSE, 1L);
    response_code = curl_easy_perform(curlOBJ);
    if(response_code != CURLE_OK){
      networkListener->cbiNetworkStatus("NETWORK ERROR", response_code);
     }else{
      networkListener->cbiNetworkStatus("NETWORK OK", response_code); 
        /* now extract transfer info */
      curl_easy_getinfo(curlOBJ, CURLINFO_SPEED_UPLOAD, &speed_upload);
      curl_easy_getinfo(curlOBJ, CURLINFO_TOTAL_TIME, &total_time);

      fprintf(stderr, "Speed: %.3f bytes/sec during %.3f seconds\n",
              speed_upload, total_time);
      
    }
     }
        
  }
  
void NetworkHandler::updateDataProgress(double TotalToDownload, double NowDownloaded, 
                    double TotalToUpload, double NowUploaded){
	if(upload){
      networkListener->cbiProgressLevel("FILE UPLOAD", NowUploaded, TotalToUpload);
        }else{
      networkListener->cbiProgressLevel("FILE DOWNLOAD", NowDownloaded, TotalToDownload);
        }	      
		    }
CURLcode NetworkHandler::curl_fetch_url(CURL *ch, const char *url, struct curl_fetch_st *fetch){
  CURLcode rcode; 
  fetch->payload = (char *) calloc(1, sizeof(fetch->payload));
 
    /* check payload */
    if (fetch->payload == NULL) {
        /* log error */
        fprintf(stderr, "ERROR: Failed to allocate payload in curl_fetch_url");
        /* return error */
        return CURLE_FAILED_INIT;
    }
 
    /* init size */
    fetch->size = 0;
    /* set url to fetch */
    curl_easy_setopt(curlOBJ, CURLOPT_URL, url);
 
    /* set calback function */
    curl_easy_setopt(curlOBJ, CURLOPT_WRITEFUNCTION, curl_callback);
 
    /* pass fetch struct pointer */
    curl_easy_setopt(curlOBJ, CURLOPT_WRITEDATA, (void *) fetch);
 
    /* set default user agent */
    curl_easy_setopt(curlOBJ, CURLOPT_USERAGENT, "libcurl-agent/1.0");
 
    /* set timeout */
    curl_easy_setopt(curlOBJ, CURLOPT_TIMEOUT, 5);
 
    /* enable location redirects */
    curl_easy_setopt(curlOBJ, CURLOPT_FOLLOWLOCATION, 1);
 
    /* set maximum allowed redirects */
    curl_easy_setopt(curlOBJ, CURLOPT_MAXREDIRS, 1);
 
    /* fetch the url */
    rcode = curl_easy_perform(curlOBJ);
 
    /* return */
    return rcode;
    
}
size_t NetworkHandler::curl_callback(void *contents, size_t size, size_t nmemb, void *userp){
  
  size_t realsize = size * nmemb;                             /* calculate buffer size */
    struct curl_fetch_st *p = (struct curl_fetch_st *) userp;   /* cast pointer to fetch struct */
 
    /* expand buffer */
    p->payload = (char *) realloc(p->payload, p->size + realsize + 1);
 
    /* check buffer */
    if (p->payload == NULL) {
      /* this isn't good */
      fprintf(stderr, "ERROR: Failed to expand buffer in curl_callback");
      /* free buffer */
      free(p->payload);
      /* return */
      return -1;
    }
 
    /* copy contents to buffer */
    memcpy(&(p->payload[p->size]), contents, realsize);
    static_cast<NetworkHandler*>(userp)->setData(p); 
    /* set new buffer size */
    p->size += realsize;
 
    /* ensure null termination */
    p->payload[p->size] = 0;
 
    /* return size */
    return realsize;
}
void NetworkHandler::setData(struct curl_fetch_st *data_load){
     this->data_set = data_load;
}		    		    
int NetworkHandler::progressFunction(void* ptr, double TotalToDownload, double NowDownloaded, 
                    double TotalToUpload, double NowUploaded){
    
	static_cast<NetworkHandler*>(ptr)->updateDataProgress(TotalToDownload,NowDownloaded,TotalToUpload,NowUploaded);	      
		    }
int NetworkHandler::responseCode(){
    return response_code;
  }

