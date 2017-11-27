#define CPPHTTPLIB_OPENSSL_SUPPORT


#include "lib/httplib.h"
#include "lib/json.hpp"
#include <iostream>
#include <memory>
#include "manager/SensiboManager.h"


using json = nlohmann::json;


std::string host = "home.sensibo.com"; //TODO: static and final??
int port = 443;//TODO: static and final??


std::string apiKey = "FdNABENzMCuRt7niVUgSm8oxVvXi85"; //TODO: static and final??


int main() {

    SensiboManager sensiboManager(host, port);
    auto devices = sensiboManager.GetDevicesInfo(apiKey);

    for (auto const &device : devices) {
        std::cout << device.first  // string (key)
                  << ':'
                  << device.second.toString() // string's value
                  << std::endl;
    }









/*



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





    for (const std::string &pod : pods) {
        auto responsePost = sensiboManager.PostAcState(pod, apiKey, j2.dump(), contentType);
        sensiboManager.PrintResponse(responsePost);
    }

*/


    return 0;
}



