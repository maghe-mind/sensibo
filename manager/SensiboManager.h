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


class SensiboManager {

public:
    SensiboManager(std::string host, int port);

    void PrintResponse(std::shared_ptr<httplib::Response> states);

    std::shared_ptr<httplib::Response> GetStates(std::string uid, std::string apiKey);

    std::shared_ptr<httplib::Response>
    PostAcState(std::string uid, std::string apiKey, std::basic_string<char> message, std::string contentType);

private:
    httplib::SSLClient cli;
};


#endif //SENSIBO_SENSIBOMANAGER_H
