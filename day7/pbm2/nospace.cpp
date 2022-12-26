//#define DEBUG

#include <iostream>
#include <fstream>
#include <string>
#include "directory.h"
using namespace std;

int main(){
    ifstream inFile("input.txt");
    string line;
    Directory root("root");
    Directory* curDir = &root;
    getline(inFile, line); //nesseescary and I dont feel like explaining why

#ifdef DEBUG
    //check root size with no folder
    cout << curDir->calculateTotalSize() << endl;
    //add a file
    curDir->addFile(500);
    cout << curDir->calculateTotalSize() << endl;
    curDir->addFile(500);
    cout << curDir->calculateTotalSize() << endl;
    //add a subfolder
    Directory* subfolder = new Directory("A");
    curDir->addSubfolder(*subfolder);
    //check if 'A' knows its parent
    cout << subfolder->getParentFolder()->getFolderName() << endl;
    //create B and C
    subfolder = new Directory("B");
    curDir->addSubfolder(*subfolder);
    subfolder->addFile(250);
    subfolder = new Directory("C");
    curDir->addSubfolder(*subfolder);
    subfolder->addFile(300);
    cout << curDir->calculateTotalSize() << endl;
    // reate D within B and add a file in D. Check B's size, then go back to root then C
    curDir = curDir->returnSubfolder("B");
    cout << curDir->getFolderName() << endl;
    subfolder = new Directory("D");
    curDir->addSubfolder(*subfolder);
    subfolder->addFile(125);
    cout << curDir->calculateTotalSize() << endl;
    curDir = curDir->getParentFolder();
    cout << curDir->getFolderName() << endl;
    cout << curDir->calculateTotalSize() << endl;




#else


    //this entire segment here builds the root directory from input
    while(getline(inFile, line)){
        if(line[0] != '$'){
            if(line[0] - '0' <= 9 && line[0] - '0' >= 0){ //this is a file
                unsigned int fileSize = 0;
                string stringNum = line.substr(0, line.find(' '));
                fileSize = stoi(stringNum);
                curDir->addFile(fileSize);
            } else{ //this is a folder
                Directory* subfolder = new Directory(line.substr(4));
                curDir->addSubfolder(*subfolder);
            }
        } else if(line[2] == 'c'){ //changing curDir
            if(line[5] == '.'){ //going back
                curDir = curDir->getParentFolder();
            } else{ //going down
                curDir = curDir->returnSubfolder(line.substr(5));
            }
            if(curDir == NULL){
                cout << "WARNING: CURRENT DIRECTORY IS NULL. HOW IS THIS POSSIBLE?" << endl;
                break;
            }
        } //last case is "$ ls" which doesn't matter
    }

    //cout << root.doTheThing() << endl;

    //lets look at the size of root's size and check how far away it is from 30 mb.
    //we then check each subdirectory's size, and ignore the ones that are below this delete size.
    //if we find a folder that's close to this delete size but not under it, we keep track of it with a pointer.
    Directory* whatweneed = root.doTheSecondThing(root.calculateTotalSize() - 30000000, 70000000);
    cout << whatweneed->calculateTotalSize() << endl;
    cout << root.calculateTotalSize() - 30000000 << endl;
#endif
    inFile.close();
}
