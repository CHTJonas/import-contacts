#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class contactImporter {
    private:
        string filepath;
        int rows;
        int columns;
        vector< vector<string> > table;

        vector<string> loadFromDisk() {
            vector<string> CSVlines;
            string readString;
            ifstream fileStream (filepath);
            if (fileStream.is_open()) {
                while (fileStream.good()) {
                    getline(fileStream, readString);
                    CSVlines.push_back(readString);
                }
                fileStream.close();
                return CSVlines;
            }
            else {
                string message = "Unable to read from file: ";
                message.append(filepath);
                throw badFileException(message);
            }
        }

    public:
        contactImporter(string path) {
            filepath = path;
            vector<string> lines;
            try {
                lines = loadFromDisk();
            }
            catch (badFileException ex) {
                print(ex.message());
                exit(1);
            }
            rows = lines.size();
            vector<string> test = split(lines[0], ',');
            columns = split(lines[0], ',').size();
            for (int i=0 ; i<rows ; i++) {
                table.push_back( split(lines[i], ',') );
            }
        }

        void iread() {
            print(I_READ_MESSAGE);
            for (int row = 0 ; row < rows ; row++) {
                string output = "";
                for (int column = 0 ; column < columns ; column++) {
                    string cellContents = table[row][column];
                    output.append(cellContents);
                    if (column != columns - 1) {
                        output.append(string(","));
                    }
                }
                print(output);
            }
        }

        vector<string> getColumn(int col) {
            vector<string> result(rows);
            for (int i = 0 ; i < rows ; i++) {
                result[i] = table[i][col];
            }
            return result;
        }

        vector<string> getColumn(int col, bool omitFirst) {
            if (omitFirst == false) {
                return getColumn(col);
            }
            // vector<string> result(rows - 1);
            // for (int i=1 ; i<rows ; i++) {
            //     result[i-1] = table[i][col];
            // }
            vector<string> result = getColumn(col);
            result.erase(result.begin());
            return result;
        }
};