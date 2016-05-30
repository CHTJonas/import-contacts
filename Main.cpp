#include <iostream>

#include "textStrings.cpp"
#include "functions.cpp"
#include "exceptions.cpp"
#include "contactImporter.cpp"
#include "contactExporter.cpp"

using namespace std;

const string version      = "1";
const string revisionDate = "20160530T2303";

int main() {
    print("Version: " + version + ", last revised " + revisionDate);
    print();

    print(READPATH_ENTRY_MESSAGE);
    contactImporter importer(read());

    print();

    // print out the stuff
		importer.iread();

    print();

    // check to see if there is a header row
    bool omitFirst;
    string input;
    while (input.compare("yes") != 0 && input.compare("no") != 0) {
        print(OMIT_FIRSTROW_MESSAGE);
        input = read();
    }
    if (input.compare("yes") == 0) {
        omitFirst = true;
    }
    if (input.compare("no") == 0) {
        omitFirst = false;
    }

    // establish which columns have the stuff in
		print(NAMES_ENTRY_MESSAGE);
		int namesCol = stoi(read());
    print(CRSID_ENTRY_MESSAGE);
		int crsidCol = stoi(read());
    print(MOBILE_ENTRY_MESSAGE);
		int mobileCol = stoi(read());

    // initialise arrays
		vector<string> fullNames = importer.getColumn(namesCol, omitFirst);
		vector<string> crsids = importer.getColumn(crsidCol, omitFirst);
		vector<string> mobileNumbers = importer.getColumn(mobileCol, omitFirst);
		vector<string> firstNames;
		vector<string> lastNames;
		for (int i = 0 ; i < fullNames.size() ; i++) {
        vector<string> splitPart = split(fullNames[i], ' ');
        firstNames.push_back(splitPart[0]);
        lastNames.push_back(splitPart[splitPart.size() - 1]);
		}
		vector<string> emails;
		for (int i = 0 ; i < crsids.size() ; i++) {
        string emailAddress = crsids[i];
        emailAddress.append("@cam.ac.uk");
        emails.push_back(emailAddress);
		}

    print();

    print(SAVEPATH_ENTRY_MESSAGE);
    contactExporter exporter(read(), firstNames, lastNames, mobileNumbers, crsids, emails);

    print();

    // save the stuff
		exporter.write();

    return 0;
}