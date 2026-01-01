#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class ConfigClass {
public:
    string host;
    int port;
    string username;
    string password;

    ConfigClass() = default;
    ConfigClass(string h, int p, string u, string pass)
        : host(h), port(p), username(u), password(pass) {}
};

namespace nlohmann {
    template<>
    struct adl_serializer<ConfigClass> {
        static void to_json(json &j, const ConfigClass &c) {
            j = json{
                {"host", c.host},
                {"port", c.port},
                {"username", c.username},
                {"password", c.password}
            };
        }

        static void from_json(const json &j, ConfigClass &c) {
            c.host = j.at("host").get<string>();
            c.port = j.at("port").get<int>();
            c.username = j.at("username").get<string>();
            c.password = j.at("password").get<string>();
        }
    };
}

struct ConfigStruct {
    string host;
    int port;
    string username;
    string password;
};

namespace nlohmann {
    template<>
    struct adl_serializer<ConfigStruct> {
        static void to_json(json &j, const ConfigStruct &c) {
            j = json{
                {"host", c.host},
                {"port", c.port},
                {"username", c.username},
                {"password", c.password}
            };
        }

        static void from_json(const json &j, ConfigStruct &c) {
            c.host = j.at("host").get<string>();
            c.port = j.at("port").get<int>();
            c.username = j.at("username").get<string>();
            c.password = j.at("password").get<string>();
        }
    };
}

int main() {
    ConfigClass config_class("localhost", 8080, "admin", "admin123");
    ConfigStruct config_struct{"localhost", 8080, "admin", "admin123"};

    json j_class = config_class;
    json j_struct = config_struct;

    cout << j_class.dump(4) << endl;
    cout << j_struct.dump(4) << endl;

    string json_string = R"(
    {
        "host": "localhost",
        "port": 8888,
        "username": "admin",
        "password": "admin123"
    })";

    config_class = json::parse(json_string).get<ConfigClass>();
    config_struct = json::parse(json_string).get<ConfigStruct>();

    cout << "loaded class " << config_class.host << endl;
    cout << "loaded struct " << config_struct.host << endl;

    return 0;
}
