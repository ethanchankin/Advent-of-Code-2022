#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;
    getline(inFile, line);
    uint searchLength = 14;
    string set = line.substr(0, searchLength);
    uint iterate = 0;

    for(uint i = 0; i < line.length(); i++){
        //check if all of set is different
        bool different = true;
        for(uint j = 0; j < searchLength; j++){
            if(set.find(set[j]) != set.rfind(set[j])){
                different = false;
                break;
            }
        }
        if(different){
            break;
        } else{
            iterate++;
            set = line.substr(iterate, searchLength);
        }
    }

    cout << iterate + searchLength << endl;

    inFile.close();
}
