 #include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line1, line2, line3;
    int total = 0;

    while(getline(inFile, line1) && getline(inFile, line2) && getline(inFile, line3)){
        //iterate through each character in string 1 with each character in string 2. if a character match is found, iterate that character from string 1 with each character in string 3 for a match.
        char common = 0;
        for(int i = 0; i < line1.length(); i++){
            for(int j = 0; j < line2.length(); j++){
                if(line1[i] == line2[j]){
                    for(int l = 0; l < line3.length(); l++){
                        if(line1[i] == line3[l]){
                            common = line1[i];
                            goto endloop; //not bad (still)
                        }
                    }
                }
            }
        }

        endloop:
        if(common > 96){ //could find a way to do this without an if statement but nah...
            total += (common - 42) % 27;
        } else{
            total += (common + 15) % 53;
        }
    }
    cout << total << endl;
}
