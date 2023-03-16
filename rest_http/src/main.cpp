#include "crow.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        std::string paths = "paths = [\n add/\n sub/\n div/\n]";
        return paths;
    });

    // now only works via json and not multipart, learn to accept multipart
    CROW_ROUTE(app, "/add")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400);
        int sum = x["number1"].i()+x["number2"].i();
        std::ostringstream os;
        os << sum;
        return crow::response{os.str()};
    });

    CROW_ROUTE(app, "/sub")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400);
        int sub = x["number1"].i()-x["number2"].i();
        std::ostringstream os;
        os << sub;
        return crow::response{os.str()};
    });

    CROW_ROUTE(app, "/div")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400);
        int div = x["number1"].i()/x["number2"].i();
        
        std::ostringstream os;
        os << div; 
        return crow::response{os.str()};
    });

    app.port(18080).run();
}
