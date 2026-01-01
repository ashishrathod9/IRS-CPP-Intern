#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;
class User {
public:
    int id;
    string name;
    string email;
    int age;

    json to_json() const {
        return json{{"id", id}, {"name", name}, {"email", email}, {"age", age}};
    }

    static User from_json(const json& j) {
        User u;
        u.id = j["id"];
        u.name = j["name"];
        u.email = j["email"];
        u.age = j["age"];
        return u;
    }

    void display() const {
        cout << "ID: " << id << " | Name: " << name
             << " | Email: " << email << " | Age: " << age << endl;
    }
};

class JSONDatabase {
private:
    string filename;
    json data;

    void load() {
        ifstream file(filename);
        if (file.is_open()) {
            try {
                file >> data;
            } catch (...) {
                data = json::array();
            }
            file.close();
        } else {
            data = json::array();
        }
    }

    void save() {
        ofstream file(filename);
        if (file.is_open()) {
            file << data.dump(4);
            file.close();
        }
    }

    int get_next_id() {
        int max_id = 0;
        for (const auto& item : data) {
            if (item["id"] > max_id) {
                max_id = item["id"];
            }
        }
        return max_id + 1;
    }

public:
    JSONDatabase(const string& fname) : filename(fname) {
        load();
    }

    // CREATE
    void create(const User& user) {
        User new_user = user;
        new_user.id = get_next_id();
        data.push_back(new_user.to_json());
        save();
        cout << "User created with ID: " << new_user.id << endl;
    }

    // READ ALL
    vector<User> read_all() {
        vector<User> users;
        for (const auto& item : data) {
            users.push_back(User::from_json(item));
        }
        return users;
    }

    // READ ONE
    bool read_one(int id, User& user) {
        for (const auto& item : data) {
            if (item["id"] == id) {
                user = User::from_json(item);
                return true;
            }
        }
        return false;
    }

    // UPDATE
    bool update(int id, const User& updated_user) {
        for (auto& item : data) {
            if (item["id"] == id) {
                item["name"] = updated_user.name;
                item["email"] = updated_user.email;
                item["age"] = updated_user.age;
                save();
                cout << "User " << id << " updated successfully!" << endl;
                return true;
            }
        }
        cout << "User " << id << " not found!" << endl;
        return false;
    }

    // DELETE
    bool remove(int id) {
        for (size_t i = 0; i < data.size(); i++) {
            if (data[i]["id"] == id) {
                data.erase(i);
                save();
                cout << "User " << id << " deleted successfully!" << endl;
                return true;
            }
        }
        cout << "User " << id << " not found!" << endl;
        return false;
    }
};

void display_menu() {
    cout << "\n=== JSON CRUD Menu ===" << endl;
    cout << "1. Create User" << endl;
    cout << "2. View All Users" << endl;
    cout << "3. View User by ID" << endl;
    cout << "4. Update User" << endl;
    cout << "5. Delete User" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    JSONDatabase db("users.json");
    int choice;

    while (true) {
        display_menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                User user;
                cout << "Enter name: ";
                getline(cin, user.name);
                cout << "Enter email: ";
                getline(cin, user.email);
                cout << "Enter age: ";
                cin >> user.age;
                db.create(user);
                break;
            }
            case 2: {
                auto users = db.read_all();
                cout << "\n=== All Users ===" << endl;
                if (users.empty()) {
                    cout << "No users found!" << endl;
                } else {
                    for (const auto& u : users) {
                        u.display();
                    }
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter user ID: ";
                cin >> id;
                User user;
                if (db.read_one(id, user)) {
                    cout << "\n=== User Details ===" << endl;
                    user.display();
                } else {
                    cout << "User not found!" << endl;
                }
                break;
            }
            case 4: {
                int id;
                cout << "Enter user ID to update: ";
                cin >> id;
                cin.ignore();
                User user;
                if (db.read_one(id, user)) {
                    cout << "Enter new name (current: " << user.name << "): ";
                    getline(cin, user.name);
                    cout << "Enter new email (current: " << user.email << "): ";
                    getline(cin, user.email);
                    cout << "Enter new age (current: " << user.age << "): ";
                    cin >> user.age;
                    db.update(id, user);
                } else {
                    cout << "User not found!" << endl;
                }
                break;
            }
            case 5: {
                int id;
                cout << "Enter user ID to delete: ";
                cin >> id;
                db.remove(id);
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
