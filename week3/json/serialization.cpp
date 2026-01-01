#include <iostream>
#include <optional>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

namespace nlohmann {
    template<typename T>
    struct adl_serializer<std::optional<T>> {
        static void to_json(json& j, const optional<T>& opt) {
            if (opt.has_value()) {
                j = *opt;
            } else {
                j = nullptr;
            }
        }

        static void from_json(const json& j, optional<T>& opt) {
            if (j.is_null()) {
                opt.reset();
            } else {
                opt = j.get<T>();
            }
        }
    };
}

struct UserProfile {
    string username;
    optional<string> bio;
    optional<int> age;
    vector<string> interests;
};

// Free functions for UserProfile
void to_json(json& j, const UserProfile& u) {
    j = json{
        {"username", u.username},
        {"bio", u.bio},
        {"age", u.age},
        {"interests", u.interests}
    };
}

void from_json(const json& j, UserProfile& u) {
    j.at("username").get_to(u.username);
    j.at("bio").get_to(u.bio);
    j.at("age").get_to(u.age);
    j.at("interests").get_to(u.interests);
}

int main() {
    UserProfile u{
        "bharat",
        optional<string>("sde"),
        nullopt,
        {"watching", "reading", "playing"}
    };

    json j = u;
    cout << j.dump(4) << endl;


    auto u2 = j.get<UserProfile>();
    cout << "username: " << u2.username << endl;

    return 0;
}
