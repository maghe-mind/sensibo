#define CPPHTTPLIB_OPENSSL_SUPPORT


#include "httplib.h"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

std::shared_ptr<httplib::Response> getStates(std::string podUid, std::string basic_string);

void PrintResponse(std::shared_ptr<httplib::Response> states);//TODO: const??







std::string host = "home.sensibo.com"; //TODO: static and final??
int port = 443;//TODO: static and final??
httplib::SSLClient cli(host.c_str(), port); // TODO: in the constructor

std::string podUid = "kvDso2fP"; //TODO: a list of podUid. Create a method
std::string apiKey = "FdNABENzMCuRt7niVUgSm8oxVvXi85"; //TODO: static and final??


int main() {

    auto states = getStates(podUid,apiKey);

    PrintResponse(states);

/*
    auto res = cli.get("/api/v2/pods/kvDso2fP/acStates?apiKey=FdNABENzMCuRt7niVUgSm8oxVvXi85");
    if (res && res->status == 200) {
        std::cout << res->body << std::endl;

        // parse explicitly
        auto j3 = json::parse(res->body);
        std::cout << "JSON" << std::endl;
        std::cout << j3 << std::endl;
    } else {
        std::cout << "error!!!" << std::endl;
    }


    // correct post request
    //{"acState": { "on": false, "targetTemperature": 28, "temperatureUnit": "C", "mode": "auto", "swing": "rangeFull" }}
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


    std::string str = j2.dump();
    std::cout << str << std::endl;

    std::replace(str.begin(), str.end(), ' ', 'c');
    std::cout << str << std::endl;

    std::string content = "{\"acState\": { \"on\": false, \"targetTemperature\": 28, \"temperatureUnit\": \"C\", \"mode\": \"auto\", \"swing\": \"rangeFull\" }}";
    std::cout << content << std::endl;


    res = cli.post("/api/v2/pods/kvDso2fP/acStates?apiKey=FdNABENzMCuRt7niVUgSm8oxVvXi85", str, "application/json");
    if (res && res->status == 200) {
        std::cout << res->body << std::endl;

        // parse explicitly
        auto j3 = json::parse(res->body);
        std::cout << "JSON" << std::endl;
        std::cout << j3 << std::endl;
    } else {
        std::cout << "error!!!" << std::endl;
        std::cout << res->body << std::endl;
    }
    // https://home.sensibo.com/api/v2/pods/kvDso2fP/acStates?apiKey=FdNABENzMCuRt7niVUgSm8oxVvXi85


*/







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

std::shared_ptr<httplib::Response> getStates(std::string uid, std::string apiKey) {

    std::string path = "/api/v2/pods/" + uid + "/acStates?apiKey=" + apiKey;
    std::shared_ptr<httplib::Response> res = cli.get(path.c_str());
    return res;

}