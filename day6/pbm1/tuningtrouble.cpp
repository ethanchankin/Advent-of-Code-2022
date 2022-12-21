#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;
    getline(inFile, line);
    string set = line.substr(0, 4);
    uint iterate = 0;

    for(uint i = 0; i < line.length(); i++){
        //check if all of set is different
        char A = set[0], B = set[1], C = set[2], D = set[3];
        if(A == B || A == C || A == D || B == C || B == D || C == D){
            iterate++;
            set = line.substr(iterate, iterate + 4);
        } else{
            break;
        }
    }

    cout << iterate + 4 << endl;

    inFile.close();
}
