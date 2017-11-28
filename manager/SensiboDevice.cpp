//
// Created by maghe on 24/11/17.
//

#include "SensiboDevice.h"
#include "SensiboAcState.h"

SensiboDevice::SensiboDevice(std::string pod, std::string roomName, std::string rawdata,
                             SensiboAcState sensiboCurrentAcState) {
    this->pod = pod;
    this->roomName = roomName;
    this->rawdata = rawdata;
    this->sensiboCurrentAcState = sensiboCurrentAcState;
}

std::string SensiboDevice::toString() const {
    return pod + "," + roomName + "," + rawdata;
}

std::string SensiboDevice::getPod() const {
    return pod;
}

std::string SensiboDevice::getRoomName() const {
    return roomName;
}

std::string SensiboDevice::getRawdata() const {
    return rawdata;
}

SensiboAcState SensiboDevice::getSensiboCurrentAcState() const {
    return sensiboCurrentAcState;
}
