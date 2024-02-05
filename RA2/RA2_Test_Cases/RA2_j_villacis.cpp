#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    ifstream file;
    string line;
    string file_name;
    string max_comment_length_string="";
    string max_noncomment_length_string="";
    int commented_lines = 0;
    int total_lines = 0;
    int max_comment_length = 0;
    int max_noncomment_length=0;
    cout << "Enter the name of a file to read from:" << endl;
    cin >> file_name;

    file.open(file_name.c_str());
    
    //can't open file
    if(!file){
        cerr << "File cannot be opened " << file_name << endl;
        return 0;
    }

    //opens file
    while(getline(file,line)){
        int temp_comment_line=0;
        int temp_noncomment_line=0;
        total_lines++;

        //for comment line 
        if(line.substr(0,2) == "//" || line.substr(0,2) == "##"){
            commented_lines++;
            while (temp_comment_line < line.length()){
                temp_comment_line++;
            }
            //check if it is the greater than max_comment_length
            if(temp_comment_line > max_comment_length){
                max_comment_length = temp_comment_line;
                max_comment_length_string=line;
            }
        }else{
            //this is for the noncomment line
            while (temp_noncomment_line < line.length()){
                temp_noncomment_line++;
            }
            //check if it is the greater than max_noncomment_length
            if(temp_noncomment_line > max_noncomment_length){
                max_noncomment_length = temp_noncomment_line;
                max_noncomment_length_string=line;
            }
        }

    }

    //close file
    file.close();

    //print all the info
    cout << "\nTotal Number of Lines: " << total_lines << endl;
    cout << "Number of commented lines: " << commented_lines << endl;
    cout << "Maximum Length of commented lines: " << max_comment_length << endl;
    cout << "Maximum Length of non-commented lines: " << max_noncomment_length << endl;
    cout << "Commented line of maximum length: \"" << max_comment_length_string << "\""<< endl;
    cout << "Non-commented line of maximum length: \"" << max_noncomment_length_string << "\"" << endl;
    return 0;
}
