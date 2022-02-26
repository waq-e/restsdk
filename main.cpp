#include <iostream>
#include "cpprest/containerstream.h"
#include "cpprest/filestream.h"
#include "cpprest/http_client.h"
#include "cpprest/json.h"
#include "cpprest/producerconsumerstream.h"
#include "cpprest/http_client.h"
#include <sstream>
#include <string>
#include <cstdio>

void integerLiterals();

using namespace std;
using namespace web;
// #using namespace web::json;
using namespace web::http;
using namespace web::http::client;
// #using namespace utility;
// #using namespace utility::conversions;


int main() {

    integerLiterals();

    using namespace std::literals; // enables the usage of 24h, 1ms, 1s instead of
    // e.g. std::chrono::hours(24), accordingly

    const std::chrono::time_point<std::chrono::system_clock> now =
            std::chrono::system_clock::now();

    const std::time_t start = std::chrono::system_clock::to_time_t(now - 2160h);
    const std::time_t end = std::chrono::system_clock::to_time_t(now);

    char url1[] = "https://query1.finance.yahoo.com/v7/finance/download/AAA?period1=1642307027&period2=1645307027&interval=1d&events=history&includeAdjustedClose=true";
    string url2{
            "https://query1.finance.yahoo.com/v7/finance/download/AAA?period1=1642307027&period2=1645307027&interval=1d&events=history&includeAdjustedClose=true"};
    string url3{"https://query1.finance.yahoo.com/v7/finance/download/"};
    url3.append("AAA");
    url3.append("?period1=");
    url3.append(to_string(start));
    url3.append("&period2=");
    url3.append(to_string(end));
    url3.append("&interval=1d&events=history&includeAdjustedClose=true");
    // char url[] = "https://httpbin.org/ip";

    //http_client client("https://httpbin.org/ip");
    http_client client(url3);

    client.request(methods::GET).then([](const http_response &response) {
        if (response.status_code() == status_codes::OK) {
            auto body = response.extract_string().get();
            std::cout << body;
            // getchar();
        }
    }).wait();


    return 0;
}

void integerLiterals() {
    int number01{-123L};      cout << number01 << endl;
    int number02{+123};       cout << number02 << endl;
    int number03{123};        cout << number03 << endl;
    int number04{22'333};     cout << number04 << endl;
    int number05{98U};        cout << number05 << endl;
    int number06{-1'234LL};   cout << number06 << endl;
    int number07{12'345ULL};  cout << number07 << endl;
    int number08{7};          cout << number08 << endl;
}
