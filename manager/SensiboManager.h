//
// Created by maghe on 24/11/17.
//

#ifndef SENSIBO_SENSIBOMANAGER_H
#define SENSIBO_SENSIBOMANAGER_H

#define CPPHTTPLIB_OPENSSL_SUPPORT //TODO: to remove, not useful

#include "../lib/httplib.h"
#include "../lib/json.hpp"
#include <iostream>
#include <memory>
#include "SensiboDevice.h"


class SensiboManager {

public:
    SensiboManager(std::string host, int port);

    std::vector<std::string> GetPods();

    std::map<std::string, SensiboDevice> GetDevicesInfo();

    std::string GetField(std::string pod, std::string fieldName);

    std::shared_ptr<httplib::Response>
    PostAcState(std::string uid, std::string apiKey, std::basic_string<char> message, std::string contentType);


/*
    void PrintResponse(std::shared_ptr<httplib::Response> states);

    std::shared_ptr<httplib::Response> GetStates(std::string uid, std::string apiKey);
*/

private:
    httplib::SSLClient cli;


    std::string GetRawData(std::string pod);
};


#endif //SENSIBO_SENSIBOMANAGER_H
