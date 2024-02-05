#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib> 
#include <cctype>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]){
    /* code */
    ifstream file;
    string word;
    int intCount = 0, realsCount = 0 , specialCount = 0; 
    map <string, int> intMap;
    map <string, int> realsMap;
    map <string, int> specialMap;  

    //only 1 arguments 
    if (argc==2){
        file.open(argv[1]);

        //open file
        if(file.is_open()){
            //file is empty
            if(file.peek() == EOF){
                cout << "File is empty." << endl;
                exit(1);
            }
            
            //read from file to get int, real value, or special 
            while (file >> word){

                //decimal counter to keep track of if its a int or decimal or none
                int deciCounter = 0;
                int deciIndex=0;
                bool isInt = true, isReal = true;

                //check if its postive or negative or if it's special 
                if (word[0]=='-' || word[0]=='+' || isdigit(word[0])){
                    for (int i = 0; i < word.length(); i++){
                        if(word[i]=='.'){
                            deciCounter++;
                            if (deciCounter==1){
                                deciIndex=i;
                            }
                            
                        }

                        if(!isdigit(word[i]) && word.length()==1){
                            isInt = false;
                        }
                    
                    }
                    //check if its decimal
                    if(word[word.length()-1] == '.' || word[0] == '.'|| !isdigit(word[deciIndex-1])){
                            isReal = false;
                    }
                    //integer    
                    if(deciCounter==0 && isInt == 1){
                        if (word[0]=='+'){
                            word = word.substr(1,word.length()-1);
                        }
                        intCount++;
                        map<string, int> ::iterator intInput = intMap.find(word);
                        if(intInput != intMap.end()){
                            intMap[word]++;
                        }else{
                            intMap[word] = 1;
                        }
                        
                    }

                    //real
                    if(deciCounter==1 && isReal == 1){
                        realsCount++;
                        if (word[0]=='+'){
                            word = word.substr(1,word.length()-1);
                        }else if(word[word.length()-1]=='0'){
                            word = word.substr(0,word.length()-1);
                        }
                        map<string, int> ::iterator realInput = realsMap.find(word);
                        if(realInput != realsMap.end()){
                            realsMap[word]++;
                        }else{
                            realsMap[word] = 1;
                        }
                    }

                }else if(word[0]=='$' && isalpha(word[1]) && isalnum(word[word.length()-1])){
                    specialCount++;
                    map<string, int> ::iterator it = specialMap.find(word);
                    if(it != specialMap.end()){
                        specialMap[word]++;
                    }else{
                        specialMap[word]=1;
                    }
                    
                }
                
            }
            

        }else{
            //file can't be open
            cout << "CANNOT OPEN THE FILE " << argv[1] << endl;
            exit (1);
        }
    

    }else{
        //no file inputs
        cout << "NO SPECIFIED INPUT FILE NAME."<< endl;
        exit (1);
    }

    //print the maps if it has content greater than 0
    cout << "Number of integers in the file: " << intCount << endl;
    cout << "Number of reals in the file: " << realsCount << endl;
    cout << "Number of special names in the file: " << specialCount << endl;

    if (intCount!=0){
        cout << "\nList of integer values and their number of occurrences:" << endl;
        map<string, int>::iterator intIT;
        int i = 0;
        int intArray[intMap.size()];
        for (intIT = intMap.begin(); intIT != intMap.end(); intIT++){
            string str = intIT->first;
            int intTemp= stoi(str);
            intArray[i] = intTemp;
            i++;
        }
        //sort array
        sort(intArray, intArray+intMap.size());
        for (int i = 0; i < intMap.size(); i++){
           cout << intArray[i]<< ": " << intMap[to_string(intArray[i])] << endl;
        }
        
    }

    if (realsCount!=0)
    {
        cout << "\nList of real values and their number of occurrences:" << endl;
        map<string, int>::iterator realIT;
        int j = 0;
        double realsArray[realsMap.size()];
        for (realIT = realsMap.begin(); realIT != realsMap.end(); realIT++){
            string str = realIT->first;
            double realTemp = stod(str);
            realsArray[j] = realTemp;
            j++;
        }
        //sort array
        sort(realsArray, realsArray+realsMap.size());
        for (int i = 0; i < realsMap.size(); i++){
            string str = to_string(realsArray[i]);
            str = str.erase(str.find_last_not_of('0')+1);
            cout << realsArray[i]<< ": " << realsMap[str] << endl;
        }
    }
    
    if (specialCount!=0){
        cout << "\nList of special names and their number of occurrences:" << endl;
        map<string, int>::iterator wordIT;
        for (wordIT = specialMap.begin(); wordIT != specialMap.end(); wordIT++){
            cout << wordIT->first << ": " << wordIT->second << endl;
        }
    }


    file.close();

    return 0;
}