#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;
    int max = 0, curTotal = 0, temp = 0;

    while(getline(inFile, line)){
        if(line[0] == 0){
            if(curTotal > max){
                max = curTotal;
            }
            curTotal = 0;
            continue;
        }
        temp = stoi(line);
        curTotal += temp;
    }

    cout << max << endl;
}
