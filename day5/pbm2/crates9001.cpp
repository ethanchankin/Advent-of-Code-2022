#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;
    getline(inFile, line);
    int howMany = 0, from = 0, to = 0;
    const int rowsOfCrates = 9; //sorry for not automating this based on input.txt
    vector<char> * crates = new vector<char>[rowsOfCrates];

    //initialize the vectors
    while(line.length() != 0){
        for(uint j = 1; j < line.length(); j += 4){
            if(line[j] >= 'A' && line[j] <= 'Z'){
                crates[(j - 1) / 4].push_back(line[j]);
            }
        }
        getline(inFile, line);
    }

    //reverse the vectors
    for(int i = 0; i < rowsOfCrates; i++){
        vector<char> copy;
        for(int j = (crates[i].size() - 1); j >= 0 ; j--){
            copy.push_back(crates[i][j]);
        }
        crates[i] = copy;
    }

    while(getline(inFile, line)){
        //know what to do
        if(line.length() == 18){
            howMany = line[5] - '0';
            from = line[12] - '0';
            to = line[17] - '0';
        } else{
            howMany = stoi(line.substr(5, 2));
            from = line[13] - '0';
            to = line[18] - '0';
        }

        //do what to do
        for(int i = 0; i < howMany; i++){
            crates[to - 1].push_back(crates[from - 1][crates[from - 1].size() + (i - howMany)]);
            crates[from - 1].erase(crates[from - 1].end() + (i - howMany));
        }
    }

    //print out the tops
    for(int i = 0; i < rowsOfCrates; i++){
        cout << crates[i].back();
    }
    cout << endl;

    //leave no mess
    delete[] crates;
    inFile.close();
}
