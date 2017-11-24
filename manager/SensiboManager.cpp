//
// Created by maghe on 24/11/17.
//

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../lib/httplib.h"
#include "../lib/json.hpp"
#include <iostream>
#include <memory>
#include "SensiboManager.h"

using json = nlohmann::json;


SensiboManager::SensiboManager(std::string host, int port) : cli(httplib::SSLClient(host.c_str(), port)) {
  }


void SensiboManager::PrintResponse(std::shared_ptr<httplib::Response> states) {
    if (states) {
        std::cout <<  "Status: " ;
        std::cout << states->status << std::endl;

        //if(states->status == 200) {

        std::cout << "BODY:" +states->body << std::endl;

        // parse explicitly
        auto j3 = json::parse(states->body);
        std::cout <<  "JSON parsing: " ;
        std::cout << j3 << std::endl;

    } else {
        std::cout << "state is null! error!" << std::endl;
    }
}

std::shared_ptr<httplib::Response> SensiboManager::GetStates(std::string uid, std::string apiKey) {

    std::string path = "/api/v2/pods/" + uid + "/acStates?apiKey=" + apiKey;
    std::shared_ptr<httplib::Response> res = cli.get(path.c_str());
    return res;

}

std::shared_ptr<httplib::Response> SensiboManager::PostAcState(std::string uid, std::string apiKey, std::basic_string<char> message, std::string contentType) {
    std::string path = "/api/v2/pods/" + uid + "/acStates?apiKey=" + apiKey;
    std::shared_ptr<httplib::Response> res = cli.post(path.c_str(), message, contentType.c_str());
    return res;
}

