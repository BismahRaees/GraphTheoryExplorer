//Hope friends
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int MAX_ROWS = 50;
const int MAX_COLS = 6;

int loadDataset(const string& filename, string data[MAX_ROWS][MAX_COLS]) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file." << endl;
        return -1;
    }

    string line, word;
    int row = 0;

    getline(file, line);
    while (getline(file, line) && row < MAX_ROWS) {
        stringstream ss(line);
        int col = 0;
        while (getline(ss, word, ',') && col < MAX_COLS) {
            data[row][col++] = word;
        }
        row++;
    }
    file.close();
    return row;
}

int findStudentIndex(string data[MAX_ROWS][MAX_COLS], int rowCount, const string& student) {
    for (int i = 0; i < rowCount; i++) {
        if (data[i][0] == student) return i;
    }
    return -1;
}

void findHops(string data[MAX_ROWS][MAX_COLS], int rowCount, int colCount, const string& student) {
    int index = findStudentIndex(data, rowCount, student);
    if (index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    bool visited[MAX_ROWS] = {false};
    string hop1[MAX_ROWS], hop2[MAX_ROWS], hop3[MAX_ROWS];
    int hop1Count = 0, hop2Count = 0, hop3Count = 0;

    for (int i = 1; i < colCount && !data[index][i].empty(); i++) {
        hop1[hop1Count++] = data[index][i];
        visited[findStudentIndex(data, rowCount, data[index][i])] = true;
    }

    for (int i = 0; i < hop1Count; i++) {
        int friendIndex = findStudentIndex(data, rowCount, hop1[i]);
        for (int j = 1; j < colCount && !data[friendIndex][j].empty(); j++) {
            int idx = findStudentIndex(data, rowCount, data[friendIndex][j]);
            if (idx != -1 && !visited[idx]) {
                hop2[hop2Count++] = data[friendIndex][j];
                visited[idx] = true;
            }
        }
    }

    for (int i = 0; i < hop2Count; i++) {
        int friendIndex = findStudentIndex(data, rowCount, hop2[i]);
        for (int j = 1; j < colCount && !data[friendIndex][j].empty(); j++) {
            int idx = findStudentIndex(data, rowCount, data[friendIndex][j]);
            if (idx != -1 && !visited[idx]) {
                hop3[hop3Count++] = data[friendIndex][j];
                visited[idx] = true;
            }
        }
    }

    cout << "1-hop friends: ";
    for (int i = 0; i < hop1Count; i++) cout << hop1[i] << " ";
    if (hop1Count == 0) cout << "None";
    cout << endl;

    cout << "2-hop friends: ";
    for (int i = 0; i < hop2Count; i++) cout << hop2[i] << " ";
    if (hop2Count == 0) cout << "None";
    cout << endl;

    cout << "3-hop friends: ";
    for (int i = 0; i < hop3Count; i++) cout << hop3[i] << " ";
    if (hop3Count == 0) cout << "None";
    cout << endl;
}

int main() {
    string data[MAX_ROWS][MAX_COLS];
    string filename = "D:\\Friends Dataset.csv";

    int rowCount = loadDataset(filename, data);
    if (rowCount == -1) return 1;

    string student;
    cout << "Enter the name of the student: ";
    getline(cin, student);

    findHops(data, rowCount, MAX_COLS, student);
   return 0;
}

