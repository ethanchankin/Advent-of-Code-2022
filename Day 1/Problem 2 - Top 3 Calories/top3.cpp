#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;
    int first = 0, second = 0, third = 0, curTotal = 0, temp = 0, temp2 = 0;

    while(getline(inFile, line)){
        if(line[0] == 0){
            if(curTotal > first){
                temp = first;
                first = curTotal;
                temp2 = second;
                second = temp;
                third = temp2;
            } else if(curTotal > second){
                temp = second;
                second = curTotal;
                third = temp;
            } else if(curTotal > third){
                third = curTotal;
            }
            curTotal = 0;
            continue;
        }
        temp = stoi(line);
        curTotal += temp;
    }

    cout << first + second + third << endl;
}

