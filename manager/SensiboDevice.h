//
// Created by maghe on 24/11/17.
//

#ifndef SENSIBO_SENSIBODEVICE_H
#define SENSIBO_SENSIBODEVICE_H



#include "iostream"

class SensiboDevice {

public:
    SensiboDevice(std::string pod, std::string roomName,std::string rawdata);
    std::string toString() const;

    std::string getPod();
    std::string getRoomName();
    std::string getRawdata();

private:
    std::string pod;
    std::string roomName;
    std::string rawdata;
};


#endif //SENSIBO_SENSIBODEVICE_H
