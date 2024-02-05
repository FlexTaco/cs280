#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>

#include <string.h>
using namespace std;

int main(int argc,char * argv[]){


    int total_words = 0, typeOneWords = 0, typeTwoWords = 0;

    fstream myFile;

    if(argc < 1){
        cerr<<" NO SPECIFIED INPUT FILE NAME."<<endl;
        exit(1);
    }

    myFile.open(argv[1]);
    
    if(myFile.fail()){
        cerr<<" CANNOT OPEN THE FILE "<<argv[1]<<endl;
        exit(1);
    }

    if(!strcmp(argv[2],"-type1") || !strcmp(argv[2],"-type1")){
        cout<<"UNRECOGNIZED FLAG"<<endl;
        exit(1);
    }

    string line,words;

    if(argc == 2){
        while(myFile >> words){
            total_words++;
            if(words.substr(0,1) == "$" && isalpha(words[1])){
                typeOneWords++;
            }
            else if(words.substr(0,1) == "@" && isalpha(words[1])){
                typeTwoWords++;
            }
        }            
    }

    else if(argc == 3 && strcmp(argv[2],"-type1")==0){
         while(myFile >> words){
            total_words++;
            if(words.substr(0,1) == "$" && isalpha(words[1])){
                typeOneWords++;
            }
        }           
    }

    else if (argc == 3 && strcmp(argv[2],"-type2")==0){
         while(myFile >> words){
            total_words++;
            if(words.substr(0,1) == "@" && isalpha(words[1])){
                typeTwoWords++;
            }
        }           
    }

    cout<<"Total number of words: "<<total_words<<endl;
    cout<<"Number of Type 1 names: "<<typeOneWords<<endl;
    cout<<"Number of Type 2 names: "<<typeTwoWords<<endl;


    
    return 0;
}