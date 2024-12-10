//Load file
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const int MAX_ROWS = 50;
    const int MAX_COLS = 6;
    string data[MAX_ROWS][MAX_COLS];
    int rowCount = 0;

    ifstream myfile("C:\\Users\\Bismah Raees\\Downloads\\Friends Dataset.csv");
    if (!myfile) {
        cerr << "Could not open file." << endl;
        return 1;
    }

    string line;
    while (getline(myfile, line) && rowCount < MAX_ROWS) {
        int colCount = 0;
        string value;
        for (char c : line) {
            if (c == ',' || c == '\n') {
                data[rowCount][colCount++] = value;
                value.clear();
            } else {
                value += c;
            }
        }
        if (!value.empty()) {
            data[rowCount][colCount++] = value;
        }
        rowCount++;
    }
    myfile.close();

    for (int i = 0; i < rowCount; i++) {
        cout << data[i][0] << " is friends with: ";
        for (int j = 1; j < MAX_COLS && !data[i][j].empty(); j++) {
            cout << data[i][j];
            if (j < MAX_COLS - 1 && !data[i][j + 1].empty()) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}