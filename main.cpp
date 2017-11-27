#define CPPHTTPLIB_OPENSSL_SUPPORT


#include "lib/httplib.h"
#include "lib/json.hpp"
#include <iostream>
#include <memory>
#include "manager/SensiboManager.h"
#include "define.h"


using json = nlohmann::json;

int main() {

    SensiboManager sensiboManager(SENSIBO_HOST, SENSIBO_PORT);
    auto devices = sensiboManager.GetDevicesInfo();

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



