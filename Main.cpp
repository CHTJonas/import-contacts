#include <iostream>

#include "TextStrings.cpp"
#include "ContactImporter.cpp"

using namespace std;

string version      = "1b";
string revisionDate = "20160509T2139";

class Box {
    public:
        double length;   // Length of a box
        double breadth;  // Breadth of a box
        double height;   // Height of a box
};

void print(string message) {
    cout << message << "\n";
}

int main() {
    print(version);
    print(revisionDate);
    return 0;
}
