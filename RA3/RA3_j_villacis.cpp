#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib> 
#include <cctype>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    ifstream file;
    string word;
    int total_word = 0, type1 = 0 , type2 = 0;    
    //only 1 or 2 arguments 
    if (argc > 1 && argc < 4){
        file.open(argv[1]);

        //open file
        if(file.is_open()){

            //file is empty
            if(file.peek() == EOF){
                cout << "File is empty." << endl;
                exit(1);
            }

            /*
            for (int i = 2; i < word.length(); i++){
                            if (word[i] != '_' || !isalnum(word[i]))
                            {
                                type1--;
                                break;
                            }
                        }
            */

            
            //read from file to get total words, type1, and type2
            while (file >> word){


                    total_word++;
                  
                    //type 1 word
                    if (word[0] == '$' && isalpha(word[1]) && isalnum(word[word.length()-1])){
                        type1++;
                        
                    }

                    //type 2 word
                    if (word[0] == '@' && isalpha(word[1]) && isalnum(word[word.length()-1])){
                        type2++;
                       
                    }
                    

            }
            

        }else{
            //file can't be open
            cout << "CANNOT OPEN THE FILE " << argv[1] << endl;
            exit (1);
        }
        if(argc==2){
            cout <<"Total number of words: " << total_word << "\nTotal number of Type 1 and Type 2 names: " << type1+type2 << endl;
            return 0; 
        }

        //-all command
        if(strcmp(argv[2],"-all") == 0){
            cout <<"Total number of words: " << total_word << "\nNumber of Type 1 names: " << type1 << "\nNumber of Type 2 names: " << type2 << endl; 

        }else if(strcmp(argv[2],"-type1") == 0){
            //-type1 command
            cout << "Number of Type 1 names: " << type1 << endl;
        }else if (strcmp(argv[2],"-type2") == 0){
            //-type2 command
            cout << "Number of Type 2 names: " << type2 << endl;
        }else{
            cout << "UNRECOGNIZED FLAG " << argv[2] << endl;
        }

    }else{
        //no file inputs
        cout << "NO SPECIFIED INPUT FILE NAME."<< endl;
        exit (1);
    }

    file.close();

    return 0;
}