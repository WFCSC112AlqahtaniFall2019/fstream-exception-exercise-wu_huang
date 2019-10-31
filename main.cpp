#include <iostream>
#include <fstream>
using namespace std;

void readEntry( int& entry);

int main() {
    ifstream inFS;
    ofstream OUT;
    inFS.open("array.txt");
    OUT.open("array.txt");
    char C;

    if (!inFS.is_open()) {
        cout << "Could not open file " << "array.txt" << endl;
        return 1;
    }
    // read table dimensions and allocate 2D array
    int nRows, nCols;
    cout<<"Enter the number of rows and columns: ";
    inFS >> nRows >> nCols;
    int** table = new int*[nRows];
    for(int i = 0; i < nRows; i++) {
        table[i] = new int[nCols];
    }


    // read table data
    OUT<<"Enter your numbers: ";
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nCols; j++) {
            try {
              readEntry(inFS, table[i][j]);
            }
            catch (int x) {
                    cout << "Entry " << i << "," << j << " not an integer, was set to " << x << ", now setting it to 0" << endl;
                    table[i][j] = 0;
                    cin.clear();
                    string tmp;
                    cin >> tmp;
            }
        }
    }
    inFS.open("array.txt");



    // write table data to the screen in transposed order
    cout << nCols << " " << nRows << endl;
    for(int i = 0; i < nCols; i++) {
        for(int j = 0; j < nRows; j++) {
            cout << table[j][i] << " ";
        }
        cout << endl;
    }


    // free memory
    for(int i = 0; i < nRows; i++) {
        delete [] table[i];
    }
    delete [] table;


}

void readEntry(ifstream& inFile, int& entry) {

    inFile >> entry;
    if(inFile.fail()) {
        throw entry;
    }
}