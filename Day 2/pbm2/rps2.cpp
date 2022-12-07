#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;

    int total = 0; //10398

    while(getline(inFile, line)){
        char oppChar = line[0];
        char instruction = line[2];

        switch(instruction){
            case 'X':
                total += (oppChar % 3) + 1; //makes cents
                break;
            case 'Y':
                total += oppChar - '='; //makes sense
                break;
            case 'Z':
                total += ((oppChar - 1) % 3) + 7; //makes sints
                break;
            default:
                cout << "ANOMALY DETECTED: 4" << endl;
        }
    }
    cout << total << endl;
}
