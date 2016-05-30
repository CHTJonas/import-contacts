#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void print() {
    cout << "\n";
}

void print(string message) {
    cout << message << "\n";
}

string read() {
    string temp;
    cin >> temp;
    return temp;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
