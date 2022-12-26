#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>
#include <string>
using namespace std;



class Directory{
private:
    unsigned int local_size = 0;

    vector<Directory*> subfolders;

    Directory* parentFolder = NULL;

    string folderName;

public:
    Directory(string name): folderName(name){}

    void addSubfolder(Directory& sub);

    void addFile(unsigned int file);

    unsigned long calculateTotalSize();

    void setParentFolder(Directory* parent);

    Directory* getParentFolder();

    string getFolderName();

    Directory* returnSubfolder(string name);

    unsigned long doTheThing();

};


#endif
