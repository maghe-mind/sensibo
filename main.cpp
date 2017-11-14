#define CPPHTTPLIB_OPENSSL_SUPPORT


#include "httplib.h"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;


int main() {

    std::string host = "home.sensibo.com";
    int port = 443;

    // std::string podUid = "kvDso2fP";
   // std::string apiKey = "FdNABENzMCuRt7niVUgSm8oxVvXi85";


    httplib::SSLClient cli(host.c_str(), port);




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
            {"acState",{
                                {"on",false},
                                {"targetTemperature",28},
                                {"temperatureUnit","C"},
                                {"mode","auto"},
                                {"swing","rangeFull"}
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








    return 0;
}
