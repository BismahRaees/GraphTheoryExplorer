//Most Popular Student
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_ENTRIES = 300;
const int MAX_UNIQUE_NAMES = 100;

int main() {
    string data[MAX_ENTRIES];
    string uniqueNames[MAX_UNIQUE_NAMES];
    int frequency[MAX_UNIQUE_NAMES] = {0};

    ifstream myfile("C:\\Users\\Bismah Raees\\Downloads\\Friends Dataset.csv");
    if (!myfile) {
        cerr << "Could not open file." << endl;
        return 1;
    }

    string value;
    int index = 0;
    while (getline(myfile, value, ',') && index < MAX_ENTRIES) {
        if (!value.empty()) {
            data[index++] = value;
        }
    }
    myfile.close();

    int uniqueCount = 0;
    for (int i = 1; i < index; i++) {
        if (!data[i].empty()) {
            bool found = false;
            for (int j = 0; j < uniqueCount; j++) {
                if (uniqueNames[j] == data[i]) {
                    frequency[j]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                uniqueNames[uniqueCount] = data[i];
                frequency[uniqueCount]++;
                uniqueCount++;
            }
        }
    }

    int maxCount = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
        }
    }

    cout << "Most popular student(s) with " << maxCount << " mentions:\n";
    for (int i = 0; i < uniqueCount; i++) {
        if (frequency[i] == maxCount) {
            cout << uniqueNames[i] << endl;
        }
    }

    return 0;
}