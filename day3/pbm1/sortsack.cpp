#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;
    int total = 0;

    while(getline(inFile, line)){
        string firstHalf = line.substr(0, line.length() / 2);
        string secondHalf = line.substr(line.length() / 2);
        char common = 0;

        for(int i = 0; i < firstHalf.length(); i++){
            for(int j = 0; j < firstHalf.length(); j++){
                if(firstHalf[i] == secondHalf[j]){
                    common = firstHalf[i];
                    goto endloop; //not bad
                }
            }
        }

        endloop:
        int tmp = total;
        if(common > 96){ //could find a way to do this without an if statement but nah...
            total += (common - 42) % 27;
        } else{
            total += (common + 15) % 53;
        }
    }
    cout << total << endl;
}
