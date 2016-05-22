#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "splitter.cpp"

using namespace std;

class ContactImporter {
    private:
        string filepath;
        int rows;
        int columns;
        vector< vector<string> > table;

        static vector<string> loadFromDisk(string filename) {
            vector<string> CSVlines;
            string readString;
            ifstream fileStream (filename);
            if (fileStream.is_open()) {
                getline(fileStream, readString);
                while (fileStream.good()) {
                    CSVlines.push_back(readString);
                    getline(fileStream, readString);
                }
                fileStream.close();
                return CSVlines;
            }
            else {
                cout << "Unable to open file";
            }
        }
    
        // private static List<String> loadFromURL(String url) throws IOException {
        //     URL destination = new URL(url);
        //     URLConnection conn = destination.openConnection();
        //     return load(new InputStreamReader(conn.getInputStream()));
        // }

    public:
        ContactImporter(string path) {
            filepath = path;
            vector<string> lines = loadFromDisk(filepath);
            rows = lines.size();
            columns = split(lines[0], ',').size();
        }

        // table = new String[rows][columns];
        // for (int i = 0 ; i < lines.length ; i++) {
        //     table[i] = ((String) lines[i]).split(",");
        // }

        void iread() {
            cout << I_READ_MESSAGE << "\n";
            for (int row=0 ; row<rows ; row++) {
                string output = "";
                for (int column=0 ; column<columns ; column++) {
                    string cell = table[row][column];
                    output += cell;
                    output += ",";
                }
                // TODO: remove the last trailing comma
                cout << output;
            }
        }

        vector<string> getColumn(int col) {
            vector<string> result(rows);
            for (int i=0 ; i<rows ; i++) {
                result[i] = table[i][col];
            }
            return result;
        }

        vector<string> getColumn(int col, bool omitFirst) {
            if (omitFirst == false) {
                return getColumn(col);
            }
            vector<string> result(rows - 1);
            for (int i=1 ; i<rows ; i++) {
                result[i-1] = table[i][col];
            }
            return result;
        }
};