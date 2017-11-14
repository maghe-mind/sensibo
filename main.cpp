#define CPPHTTPLIB_OPENSSL_SUPPORT


#include "httplib.h"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

std::shared_ptr<httplib::Response> GetStates(std::string podUid, std::string basic_string);

void PrintResponse(std::shared_ptr<httplib::Response> states);//TODO: const??

std::shared_ptr<httplib::Response> PostAcState(std::string basic_string, std::string basicString, std::basic_string<char> dump, std::string type);

std::string host = "home.sensibo.com"; //TODO: static and final??
int port = 443;//TODO: static and final??
httplib::SSLClient cli(host.c_str(), port); // TODO: in the constructor

std::string podUid = "kvDso2fP"; //TODO: a list of podUid. Create a method
std::string apiKey = "FdNABENzMCuRt7niVUgSm8oxVvXi85"; //TODO: static and final??


int main() {

   // auto responseStates = GetStates(podUid,apiKey);

    //PrintResponse(responseStates);

    json j2 = {
            {"acState", {
                                {"on", false},
                                {"targetTemperature", 28},
                                {"temperatureUnit", "C"},
                                {"mode", "auto"},
                                {"swing", "rangeFull"}
                        }
            }
    };
    std::string contentType = "application/json";

    auto responsePost = PostAcState (podUid,apiKey,j2.dump(),contentType);
    PrintResponse(responsePost);

    return 0;
}



void PrintResponse(std::shared_ptr<httplib::Response> states) {
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

std::shared_ptr<httplib::Response> GetStates(std::string uid, std::string apiKey) {

    std::string path = "/api/v2/pods/" + uid + "/acStates?apiKey=" + apiKey;
    std::shared_ptr<httplib::Response> res = cli.get(path.c_str());
    return res;

}

std::shared_ptr<httplib::Response> PostAcState(std::string uid, std::string apiKey, std::basic_string<char> message, std::string contentType) {
    std::string path = "/api/v2/pods/" + uid + "/acStates?apiKey=" + apiKey;
    std::shared_ptr<httplib::Response> res = cli.post(path.c_str(), message, contentType.c_str());
    return res;
}