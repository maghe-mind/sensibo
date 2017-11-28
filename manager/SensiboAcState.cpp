//
// Created by maghe on 28/11/17.
//

#include "SensiboAcState.h"
#include <iostream>


SensiboAcState::SensiboAcState() {
}


SensiboAcState::SensiboAcState(std::string id, bool on, std::string fanLevel, std::string temperatureUnit,
                               int targetTemperature, std::string mode, std::string swing) {

    this->id = id;
    this->on = on;
    this->fanLevel = fanLevel;
    this->temperatureUnit = temperatureUnit;
    this->targetTemperature = targetTemperature;
    this->mode = mode;
    this->swing = swing;
}
