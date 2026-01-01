#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;


// Converting to/from custom types
struct Person {
    std::string name;
    int age;
};

void to_json(json& j, const Person& p) {
    j = json{{"name", p.name}, {"age", p.age}};
}

void from_json(const json& j, Person& p) {
    j.at("name").get_to(p.name);
    j.at("age").get_to(p.age);
}


int main(){

  json j;

  j["name"] = "bharat ";
  j["surname"] = "ladva";
  j["age"] = 22;
  j["hobbies"] = {"watching", "reading", "playing"};
  j["address"] = {
    {"country", "india"},
    {"state", "gujarat"},
    {"city", "ahmadabad"},
    {"pincode", "369933"}
  };

  // cout<< j.dump(4) << endl;


  string json_string =R"(
    {
      "name": "bharat",
      "age": 34

    }

  )";

  json parsed_json = json::parse(json_string);
  cout << parsed_json.dump(4) <<  endl;

  json json_types  = {
    {"null", nullptr},
    {"bool", true},
    {"unsigned_int" , 123u},
    {"float" ,23.2},
    {"string", "hi"},
    {"array", {1,2,3}},
    {"object", {
      {"key1", "val1"},
      {"key2", "val2"},
      {"key3", "val3"}
    }}
  };

  if(json_types.is_null()){
      cout << "not null" << endl;
  }

  if(json_types.contains("array")){
    const json arr = json_types["array"];
    for(const auto & el : arr){
      cout << el << endl;
    }
  }

  if(json_types["int"].is_number_integer()){
    cout << json_types["int"]<< endl;
  }

  try{


    string name = json_types.at("string").get<string>();

    int age = json_types.at("unsigned_int").get<int>();

    cout << name << " " << age << endl;

  }catch(const exception& e){
    cout << e.what() << endl;
  }

  ofstream ofile("data.json");
  ofile << j.dump(4);
  ofile.close();

  ifstream ifile("data.json");
  json file_json;
  ifile >> file_json;
  cout << file_json.dump(4) << endl;



  // Creating nested structures
json data = {
    {"users", json::array()},
    {"settings", {
        {"theme", "dark"},
        {"notifications", true}
    }}
};

// Adding to arrays
data["users"].push_back({{"id", 1}, {"name", "Alice"}});

// Safe access with default
std::string theme = data["settings"].value("theme", "light");

// Checking existence
if (data.contains("users")) {
    for (const auto& user : data["users"]) {
        std::cout << user["name"] << std::endl;
    }
}




  return 0;




}
