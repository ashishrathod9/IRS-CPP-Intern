#include <nlohmann/json.hpp>
#include <iostream>
#include <vector>

using json = nlohmann::json;

int main() {

    std::cout << "===== CONSTRUCTION =====\n";
    json j_null;
    json j_bool = true;
    json j_int = 10;
    json j_float = 3.14;
    json j_string = "hello";

    json j_array = json::array({1, 2, 3});
    json j_object = json::object({{"name", "Ashish"}, {"age", 22}});

    std::cout << j_object.dump() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== TYPE CHECKS =====\n";
    std::cout << j_object.is_object() << "\n";
    std::cout << j_array.is_array() << "\n";
    std::cout << j_string.is_string() << "\n";
    std::cout << j_int.is_number_integer() << "\n";
    std::cout << j_float.is_number_float() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== TYPE INFO =====\n";
    std::cout << j_object.type_name() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== ELEMENT ACCESS =====\n";
    std::cout << j_object["name"] << "\n";
    std::cout << j_object.at("age") << "\n";
    std::cout << j_object.value("city", "Unknown") << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== MODIFIERS =====\n";
    j_object["city"] = "Jamnagar";
    j_object.emplace("country", "India");
    j_object.erase("age");
    std::cout << j_object.dump(2) << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== ARRAY MODIFIERS =====\n";
    j_array.push_back(4);
    j_array.emplace_back(5);
    j_array.insert(j_array.begin() + 1, 100);
    std::cout << j_array.dump() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== ITERATION =====\n";
    for (auto& [k, v] : j_object.items()) {
        std::cout << k << " => " << v << "\n";
    }
    std::cout << "\n";

    // -------------------------------------------------------

    std::cout << "===== SIZE / EMPTY =====\n";
    std::cout << j_array.size() << "\n";
    std::cout << j_array.empty() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== GET / CONVERSION =====\n";
    std::string name = j_object["name"].get<std::string>();
    int number = j_array[0].get<int>();
    std::cout << name << " " << number << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== PARSING =====\n";
    json parsed = json::parse(R"({"x":10,"y":20})");
    std::cout << parsed.dump() << "\n";
    std::cout << json::accept(R"({"a":1})") << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== COMPARISON =====\n";
    json a = 10;
    json b = 20;
    std::cout << (a < b) << "\n";
    std::cout << (a == b) << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== UPDATE / MERGE =====\n";
    json base = {{"x",1}};
    json upd = {{"x",2},{"y",3}};
    base.update(upd);
    std::cout << base.dump() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== PATCH / DIFF =====\n";
    json j1 = {{"a",1}};
    json j2 = {{"a",2}};
    json patch = json::diff(j1, j2);
    j1.patch(patch);
    std::cout << j1.dump() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== FLATTEN / UNFLATTEN =====\n";
    json nested = {{"a", {{"b", {{"c", 1}}}}}};
    json flat = nested.flatten();
    json unflat = flat.unflatten();
    std::cout << flat.dump() << "\n";
    std::cout << unflat.dump() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== BINARY FORMATS =====\n";
    auto cbor = json::to_cbor(j_object);
    json from_cbor = json::from_cbor(cbor);
    std::cout << from_cbor.dump() << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== SWAP =====\n";
    json s1 = 1, s2 = 2;
    s1.swap(s2);
    std::cout << s1 << " " << s2 << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== META =====\n";
    std::cout << json::meta().dump(2) << "\n\n";

    // -------------------------------------------------------

    std::cout << "===== EXCEPTIONS =====\n";
    try {
        j_object.at("missing");
    } catch (json::out_of_range& e) {
        std::cout << "Caught out_of_range\n";
    }

    return 0;
}
