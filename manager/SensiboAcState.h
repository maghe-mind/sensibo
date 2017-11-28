//
// Created by maghe on 28/11/17.
//

#ifndef SENSIBO_SENSIBOACSTATE_H
#define SENSIBO_SENSIBOACSTATE_H

#include <iostream>

class SensiboAcState {

public:
    SensiboAcState();// TODO: is it the correct way?
    SensiboAcState(std::string id, bool on, std::string fanLevel, std::string temperatureUnit, int targetTemperature,
                   std::string mode, std::string swing);

private:
    std::string id;
    bool on;
    std::string fanLevel;
    std::string temperatureUnit;
    int targetTemperature;
    std::string mode;
    std::string swing;
};


#endif //SENSIBO_SENSIBOACSTATE_H
