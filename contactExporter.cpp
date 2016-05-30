#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class contactExporter {
    private:
        string filepath;
        vector<string> firstNames;
        vector<string> lastNames;
        vector<string> mobileNumbers;
        vector<string> crsids;
        vector<string> emails;

        void writeToDisk() {
            int length = firstNames.size();
            ofstream file (filepath);
            if (file.is_open()) {
                for (int i = 0 ; i < length ; i++) {
                    string output = "";
                    output.append(firstNames[i] + ",");
                    output.append(lastNames[i] + ",");
                    output.append(emails[i] + ",");
                    output.append(mobileNumbers[i]);
                    if (i != length - 1) {
                        output.append("\n");
                    }
                    file << output;
                }
                file.close();
            }
            else {
                string message = "Unable to write to file: ";
                message.append(filepath);
                throw badFileException(message);
            }
        }

    public:
        contactExporter(string path, vector<string> arg_firstNames, vector<string> arg_lastNames, vector<string> arg_mobileNumbers, vector<string> arg_crsids, vector<string> arg_emails) {
            filepath = path;
            firstNames = arg_firstNames;
            lastNames = arg_lastNames;
            mobileNumbers = arg_mobileNumbers;
            crsids = arg_crsids;
            emails = arg_emails;
        }

        // write stuff here
        void write() {
            try {
                writeToDisk();
            }
            catch (badFileException ex) {
                print(ex.message());
                exit(1);
            }
        }
};