#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {
    json j;
    j["name"] = "Ashish";
    j["age"] = 21;
}

