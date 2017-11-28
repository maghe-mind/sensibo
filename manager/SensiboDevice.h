//
// Created by maghe on 24/11/17.
//

#ifndef SENSIBO_SENSIBODEVICE_H
#define SENSIBO_SENSIBODEVICE_H


#include "iostream"
#include "SensiboAcState.h"


class SensiboDevice {

public:
    SensiboDevice(std::string pod, std::string roomName, std::string rawdata, SensiboAcState sensiboCurrentAcState);

    std::string toString() const;

    std::string getPod() const;

    std::string getRoomName() const;

    std::string getRawdata() const;

    SensiboAcState getSensiboCurrentAcState() const;

private:
    std::string pod;
    std::string roomName;
    std::string rawdata;
    SensiboAcState sensiboCurrentAcState;
};


#endif //SENSIBO_SENSIBODEVICE_H
