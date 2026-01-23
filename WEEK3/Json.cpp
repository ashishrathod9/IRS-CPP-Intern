#include<iostream>
#include<nlohmann/json.hpp>

using namespace std;

using json=nlohmann::json;

int main()
{
    json config = json::object();

config["host"] = "localhost";
config["port"] = 8080;
config["debug"] = true;
config["host"]="https:/";

config["sercure"]="https:/";
config.erase("debug");
config.dump(4);
for(auto [key,value]  : config.items())
{
	cout<<key;
	cout<<value;
}

json::accept("config");


return 0;

}
