#include<string>

#ifndef NETWORK_OBJECTS_H
#define NETWORK_OBJECTS_H

struct KeyVal{
  std::string key;
  std::string value;
};

struct curl_fetch_st {
    char *payload;
    size_t size;
};

#endif // NETWORK_OBJECTS_H