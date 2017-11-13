#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "httplib.h"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;


int main() {

    httplib::SSLClient cli("home.sensibo.com", 443);

    auto res = cli.get("/api/v2/pods/kvDso2fP/acStates?apiKey=FdNABENzMCuRt7niVUgSm8oxVvXi85");
    if (res && res->status == 200) {
        std::cout << res->body << std::endl;

        // parse explicitly
        auto j3 = json::parse(res->body);
        std::cout << "JSON" << std::endl;
        std::cout << j3 << std::endl;
    }
    else  {
        std::cout << "error!!!" << std::endl;
    }

    return 0;
}