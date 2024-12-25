#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    ifstream myfile("D:\\Friends Dataset.csv");
    if(!myfile)
    {
      cout<<"File could not found:"<<endl;
      return 1;  
        
    }
    const int TROWS = 100;
    const int TNAMES = 50; //TOTAL NAMES IN A ROW
    string line;
    string rows[TROWS][TNAMES]; //STORE DATA OF EACH ROW
    int rcount = 0;
    int cc[TROWS] = {0}; //  number of columns in each row

    while (getline(myfile, line)) {
        stringstream ss(line);
        string word;
        int columnCount = 0;
        while (getline(ss, word, ',')) {
            rows[rcount][columnCount] = word;
            columnCount++;
        }
        cc[rcount] = columnCount;
        rcount++;
    }
    myfile.close();
  
    for (int i = 0; i < rcount - 1; i++)   //Compare each row with other... 
	{
        for (int j = i + 1; j < rcount; j++)  //compare current row with subsequent rows
		 {
            string n1 = rows[i][0];
            string n2 = rows[j][0];
         int eweight=0;
            cout << "Comparing " << n1 << " and " << n2 << ":" << endl;
            bool MFR = false;
            for (int k = 1; k < cc[i]; k++) //for each friend of n1
			 {
                for (int l = 1; l < cc[j]; l++) //for each friend of n2
				 {
                    if (rows[i][k] == rows[j][l]) {
                    	eweight++;
                        cout << "Mutual friend: " << rows[i][k] << endl;
                        MFR = true;
                    }
                }
            }
         cout<<"Edge weight between "<<n1<<" and "<<n2<<" = "<<eweight<<endl;
            if (!MFR) {
                cout << "No mutual friends found." << endl;
            }
            cout << endl;
        }
    }
   return 0;
}

