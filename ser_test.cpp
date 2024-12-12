#include <crow.h>
#include <iostream>

int main()
{
    crow::SimpleApp app;

    // Obsługa strony głównej
    CROW_ROUTE(app, "/")([]() {
        auto page = crow::mustache::load_text("index.html");
        return page;
        });

    // Obsługa POST z danymi
    CROW_ROUTE(app, "/submit").methods(crow::HTTPMethod::POST)([](const crow::request& req) {
        auto body = req.body; // Pobranie treści żądania
        std::cout << "Received text: " << body << std::endl; // Wypisanie w terminalu
        return crow::response(200, "Data received");
    });

    app.port(8080).multithreaded().run();
}