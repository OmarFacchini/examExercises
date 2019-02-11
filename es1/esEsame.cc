#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int lenght = 81;
const char urlBegin[] = "http://";
const char domainPathSeparator = '/'; 

//checks the parameters to be a valid word
bool wordIsUsable(const char myLetter){
    return ((myLetter >= 'a' && myLetter <= 'z') ||
            (myLetter >= 'A' && myLetter <= 'Z') ||
            (myLetter >= '0' && myLetter <= '9') ||
            (myLetter == '_'));
}

int findDomainPathSeparatorIndex(const char myWord[]){
    int index = 7;
    while((myWord[index] != domainPathSeparator) || (myWord[index] != '\0')){
        index++;
    }
    return index;
}

bool startsWith(const char myWord[]){
    for(int i = 0; i < 7; i++){
        if(myWord[i] != urlBegin[i]) return false; 
    }
    return true;
}

bool checkDomain(const char myWord[], int begin, int end){
    if(end - begin >= 2)
    for(begin; begin < end; begin++){
        if(!wordIsUsable(myWord[begin]) || myWord[begin] == '/') return false;
    }
    return true;
}

bool checkPath(const char myWord[], int begin){
    while(myWord[begin] != '\0'){
        if(!wordIsUsable(myWord[begin]) || myWord[begin] == '.') return false;
    }
    return true;
}

bool isValidUrl(const char myWord[]){
    int separator;
    if(startsWith(myWord)) separator = findDomainPathSeparatorIndex(myWord);

    checkDomain(myWord,7,separator - 1);
    checkPath(myWord,separator + 1);

    return true;
}


int main(int argc, char const *argv[]){

    if(argc != 2){
        cerr << "usage: g++ esercizio1.cc file.txt";
        exit(EXIT_FAILURE);

    }

    ifstream myFile(argv[1]);
    myFile.open(argv[1]);
    if(myFile.fail()){
        cerr << "file not available or doesn't exist";
        exit(EXIT_FAILURE);
    }

    char myWord[lenght];
    myFile >> myWord;

    while(!myFile.eof()){

        if(isValidUrl(myWord)){
            cout << myWord << endl;
        }
        myFile >> myWord;

    }
     
     myFile.close();
    
    return 0;
}

