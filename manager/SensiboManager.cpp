//
// Created by maghe on 24/11/17.
//

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "../lib/httplib.h"
#include "../lib/json.hpp"
#include <iostream>
#include <memory>
#include "SensiboManager.h"
#include "../define.h"
#include "SensiboDevice.h"
#include "map"


using json = nlohmann::json;


SensiboManager::SensiboManager(std::string host, int port) :
        cli(httplib::SSLClient(host.c_str(), port)) {

}

std::map<std::string, SensiboDevice> SensiboManager::GetDevicesInfo() {

    std::map<std::string, SensiboDevice> sensiboDevices;
    auto pods = SensiboManager::GetPods();

    for (const std::string &pod : pods) {

        std::string room = SensiboManager::GetField(pod, "room");

        std::string roomName = json::parse(room)["room"]["name"];

        std::string rawdata = SensiboManager::GetRawData(pod);

        SensiboDevice sensiboDevice(pod, roomName, rawdata);

        sensiboDevices.insert(std::pair<std::string, SensiboDevice>(pod, sensiboDevice));
    }
    return sensiboDevices;
}


std::vector<std::string> SensiboManager::GetPods() {

    std::vector<std::string> pods;
    std::string apiKey(SENSIBO_APIKEY); //TODO: I don't understand why operator + cannot be applied to char[], while in the method GetField this operator accepts it.
    std::string path = "/api/v2/users/me/pods?apiKey=" + apiKey;
    std::shared_ptr<httplib::Response> response = cli.get(path.c_str());

    if (response && response->status == 200) {
        auto parsedJsonResponse = json::parse(response->body);  //TODO: parse explicitly. Something more elegant?
        for (int i = 0; i < parsedJsonResponse["result"].size(); i++) {
            pods.push_back(parsedJsonResponse["result"][i]["id"]);
        }
    } else {
        std::cout << "No response or respose code != 200" << std::endl;
        throw std::exception(); // TODO: discuss how to manage the misbehavior
    }
    return pods;
}

std::string SensiboManager::GetField(std::string pod, std::string fieldName) {

    std::string responseResult;
    std::string path = "/api/v2/pods/" + pod
                       + "?apiKey=" + SENSIBO_APIKEY
                       + "&fields=" + fieldName;
    std::shared_ptr<httplib::Response> response = cli.get(path.c_str());

    if (response && response->status == 200) {
        auto parsedJsonResponse = json::parse(response->body);  //TODO: parse explicitly. Something more elegant?
        responseResult = parsedJsonResponse["result"].dump();

    } else {
        std::cout << "No response or respose code != 200" << std::endl;
        std::cout << response->status << std::endl;
        throw std::exception(); // TODO: discuss how to manage the misbehavior
    }
    return responseResult;
}

std::string SensiboManager::GetRawData(std::string pod) {
    return SensiboManager::GetField(pod, "");
}

std::shared_ptr<httplib::Response>
SensiboManager::PostAcState(std::string uid, std::string apiKey, std::basic_string<char> message,
                            std::string contentType) {
    std::string path = "/api/v2/pods/" + uid + "/acStates?apiKey=" + apiKey;
    std::shared_ptr<httplib::Response> res = cli.post(path.c_str(), message, contentType.c_str());
    return res;
}









/*


void SensiboManager::PrintResponse(std::shared_ptr<httplib::Response> states) {
    if (states) {
        std::cout << "Status: ";
        std::cout << states->status << std::endl;

        //if(states->status == 200) {

        std::cout << "BODY:" + states->body << std::endl;

        // parse explicitly
        auto j3 = json::parse(states->body);
        std::cout << "JSON parsing: ";
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
*/



