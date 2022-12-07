#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile("input.txt");
    string elf1Work, elf2Work;
    int total = 0;

    while(getline(inFile, elf1Work, ',') && getline(inFile, elf2Work)){
        int elf1Start = stoi(elf1Work.substr(0, elf1Work.find('-')));
        int elf1End = stoi(elf1Work.substr(elf1Work.find('-') + 1));
        int elf2Start = stoi(elf2Work.substr(0, elf2Work.find('-')));
        int elf2End = stoi(elf2Work.substr(elf2Work.find('-') + 1));

        if((elf1Start <= elf2End && elf1End >= elf2Start) || (elf2Start <= elf1End && elf2End >= elf1Start)){
            total++;
        }
    }

    cout << total << endl;
}
