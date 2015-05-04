#ifndef NETWORK_CB_INTERFACE_H
#define NETWORK_CB_INTERFACE_H
#include<string>

class NetworkCBListener{
public:
  virtual void cbiNetworkStatus(std::string, int)=0;
  virtual void cbiProgressLevel(std::string, double, double)=0;
    
};


#endif // NETWORK_CB_INTERFACE_H