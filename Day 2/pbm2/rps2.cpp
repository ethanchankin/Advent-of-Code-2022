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
        total += ((oppChar - ((((instruction - 2) % 3) - 2) * -1)) % 3) + (((instruction - 1) % 3) * 3) + 1;
    }
    cout << total << endl;
}
