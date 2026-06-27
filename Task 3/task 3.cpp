
#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void fill_values(json& node, const json& values_map) {
    if (node.is_object() && node.contains("id")) {
        int id = node["id"];
        string id_str = to_string(id);
        if (values_map.contains(id_str)) {
            node["value"] = values_map[id_str];
        }
    }

    if (node.is_array()) {
        for (auto& item : node) { 
            fill_values(item, values_map);
        }
    }
    else if (node.is_object()) {

        for (auto it = node.begin(); it != node.end(); ++it) {
            fill_values(it.value(), values_map);
        }
    }
}

int main() {
    string values_file = "C:\\Users\\Radius\\source\\repos\\Task 3\\values.json";
    string tests_file = "C:\\Users\\Radius\\source\\repos\\Task 3\\tests.json";
    string report_file = "C:\\Users\\Radius\\source\\repos\\Task 3\\report.json";

    try {
        ifstream vf(values_file);
        if (!vf.is_open()) {
            cout << "OSHIBKA: Ne mogu otkryt " << values_file << endl;
            system("pause");
            return 1;
        }

        json values_data;
        vf >> values_data;
        vf.close();
        cout << "[OK] values.json prochitan" << endl;

        json values_map;
        for (const auto& item : values_data["values"]) {
            int id = item["id"];
            string value = item["value"];
            values_map[to_string(id)] = value;
        }

        ifstream tf(tests_file);
        if (!tf.is_open()) {
            cout << "OSHIBKA: Ne mogu otkryt " << tests_file << endl;
            system("pause");
            return 1;
        }

        json tests_data;
        tf >> tests_data;
        tf.close();
        cout << "[OK] tests.json prochitan" << endl;

        fill_values(tests_data, values_map);

        ofstream rf(report_file);
        rf << tests_data.dump(4);
        rf.close();
        cout << "[OK] report.json sozdan" << endl;

        cout << "\nGOTOVO!" << endl;

    }
    catch (const exception& e) {
        cout << "OSHIBKA: " << e.what() << endl;
        system("pause");
        return 1;
    }

    system("pause");
    return 0;
}
