#include "directory.h"
#include <vector>
#include <string>

using namespace std;

void Directory::addSubfolder(Directory& sub){
    subfolders.push_back(&sub);
    sub.setParentFolder(this);
}

void Directory::addFile(unsigned int file){
    local_size += file;
}

unsigned long Directory::calculateTotalSize(){
    unsigned long total = local_size;
    for(Directory* folder : subfolders){
        total += folder->calculateTotalSize();
    }
    return total;
}

void Directory::setParentFolder(Directory * parent){
    parentFolder = parent;
}

Directory* Directory::getParentFolder(){
    return parentFolder;
}

string Directory::getFolderName(){
    return folderName;
}

Directory* Directory::returnSubfolder(string name){
    for(Directory* folder : subfolders){
        if(folder->getFolderName() == name){
            return folder;
        }
    }
    return NULL;
}

unsigned long Directory::doTheThing(){
    unsigned long total = 0;
    if(calculateTotalSize() <= 100000){
        total = calculateTotalSize();
    }
    for(Directory* folder : subfolders){
        total += folder->doTheThing();
    }
    return total;
}
