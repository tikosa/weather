#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include <iostream>
#include <thread>
#include <chrono>

// for convenience
using json = nlohmann::json;

// const std::string yerevan_location_key = "16890";
// const std::string apikey = "TBD";

template<typename T>
struct TD;

int main(int argc, char** argv) {
    std::cout << "Waiting..." << std::endl;

    std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(time_t{1550421421}));

    // std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    // std::chrono::system_clock::time_point now_c = now + std::chrono::seconds(3);
    // std::this_thread::sleep_until(now_c);

    // std::string url{"http://dataservice.accuweather.com/currentconditions/v1/"};
    // auto r = cpr::Get(cpr::Url{"http://www.httpbin.org/get"});
    // auto r = cpr::Get(cpr::Url{"http://samples.openweathermap.org/data/2.5/weather?id=2172797&appid=b6907d289e10d714a6e88b30761fae22"});
    // auto r = cpr::Get(cpr::Url{url + yerevan_location_key},
    //                             cpr::Parameters{{"apikey", apikey}, 
    //                                             {"language", "en-us"}});

    std::string url{"localhost:8000"};
    auto r = cpr::Get(cpr::Url{url});
    std::cout << "status code: " << r.status_code << std::endl;;                  // 200
    if(r.status_code != 200) {
        std::cout << "Response status is not OK. Terminating ..." << std::endl;
    }
    // r.header["content-type"];       // application/json; charset=utf-8
    // std::cout << r.text << std::endl;;                         // JSON text string

    const std::string temperature{"Temperature"};
    const std::string metric{"Metric"};
    const std::string value{"Value"};

    auto text_json = json::parse(r.text);
    auto temperature_metric_value = text_json[0][temperature][metric][value];
    std::cout << temperature_metric_value << std::endl;

    // std::string resp("{\"coord\":{\"lon\":-0.13,\"lat\":51.51},\"weather\":[{\"id\":300,\"main\":\"Drizzle\",\"description\":\"light intensity drizzle\",\"icon\":\"09d\"}],\"base\":\"stations\",\"main\":{\"temp\":280.32,\"pressure\":1012,\"humidity\":81,\"temp_min\":279.15,\"temp_max\":281.15},\"visibility\":10000,\"wind\":{\"speed\":4.1,\"deg\":80},\"clouds\":{\"all\":90},\"dt\":1485789600,\"sys\":{\"type\":1,\"id\":5091,\"message\":0.0103,\"country\":\"GB\",\"sunrise\":1485762037,\"sunset\":1485794875},\"id\":2643743,\"name\":\"London\",\"cod\":200}");
    //
    // auto j3 = json::parse(resp);
    // // TD<decltype(j3)> t;
    // auto j3_value = j3["coord"]["lon"];
    // // TD<decltype(j3_value)> t;
    // std::cout << j3["main"]["temp"] << std::endl;

    return 0;
}
