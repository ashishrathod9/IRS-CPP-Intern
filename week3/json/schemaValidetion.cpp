#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <nlohmann/json-schema.hpp>

using json = nlohmann::json;
using namespace std;

struct Dimension {
    float width;
    float height;
    float length;
};

void to_json(json &j, const Dimension &d) {
    j = json{
        {"width", d.width},
        {"height", d.height},
        {"length", d.length}
    };
}

void from_json(const json &j, Dimension &d) {
    j.at("width").get_to(d.width);
    j.at("height").get_to(d.height);
    j.at("length").get_to(d.length);
}

struct Product {
    string id;
    string name;
    float price;
    vector<string> tags;
    string status;
    Dimension dimension;

    static json schema() {
        return json{
            {"type", "object"},
            {"properties", {
                {"id", {{"type", "string"}}},
                {"name", {{"type", "string"}}},
                {"price", {{"type", "number"}}},
                {"tags", {
                    {"type", "array"},
                    {"items", {{"type", "string"}}}
                }},
                {"status", {
                    {"type", "string"},
                    {"enum", {"active", "pending", "sold"}}
                }},
                {"dimension", {{"$ref", "#/definitions/Dimension"}}}
            }},
            {"required", {"id", "name", "price", "status", "dimension"}},
            {"definitions", {
                {"Dimension", {
                    {"type", "object"},
                    {"properties", {
                        {"width", {{"type", "number"}}},
                        {"height", {{"type", "number"}}},
                        {"length", {{"type", "number"}}}
                    }},
                    {"required", {"width", "height", "length"}}
                }}
            }}
        };
    }
};

void to_json(json &j, const Product &p) {
    j = json{
        {"id", p.id},
        {"name", p.name},
        {"price", p.price},
        {"tags", p.tags},
        {"status", p.status},
        {"dimension", p.dimension}
    };
}

void from_json(const json &j, Product &p) {
    j.at("id").get_to(p.id);
    j.at("name").get_to(p.name);
    j.at("price").get_to(p.price);
    j.at("tags").get_to(p.tags);
    j.at("status").get_to(p.status);
    j.at("dimension").get_to(p.dimension);
}

int main() {
    string json_string = R"(
    {
        "id":"p123",
        "name": "apple",
        "price":100,
        "tags": [ "new", "unique","limited"],
        "status": "active",
        "dimension": {
            "width":10,
            "height":20,
            "length":30
        }
    }
    )";

    try {
        json j_product = json::parse(json_string);

        nlohmann::json_schema::json_validator validator;

        validator.set_root_schema(Product::schema());
        validator.validate(j_product);

        Product p = j_product.get<Product>();

        cout << "Product ID: " << p.id << endl;
        cout << "Name: " << p.name << endl;
        cout << "Price: " << p.price << endl;
        cout << "Height: " << p.dimension.height << endl;

    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
