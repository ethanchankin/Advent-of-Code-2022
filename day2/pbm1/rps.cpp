#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;

    int total = 0;

    while(getline(inFile, line)){
        char oppChar = line[0];
        char ownChar = line[2];

        switch(ownChar){
            case 'X':
                ownChar = 'A';
                total++;
                break;
            case 'Y':
                ownChar = 'B';
                total += 2;
                break;
            case 'Z':
                ownChar = 'C';
                total += 3;
                break;
            default:
                cout << "ANOMALY DETECTED" << endl;
                break;
        }

        if(oppChar == ownChar){
            total += 3;
        } else if((oppChar - 2 == ownChar) || (oppChar + 1 == ownChar)){ //intutive
            total += 6;
        }

    }
    cout << total << endl;
}
