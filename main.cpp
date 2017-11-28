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
     json j2 = {
            {"acState", {
                                {"on", false},
                                {"targetTemperature", 23},
                                {"temperatureUnit", "C"},
                                {"mode", "auto"},
                                {"swing", "rangeFull"}
                        }
            }
    };
    std::string contentType = "application/json";


    for (auto const &device : devices) {
        auto responsePost = sensiboManager.PostAcState(device.second.getPod(), j2.dump(), contentType);
    }
    */
    return 0;
}



