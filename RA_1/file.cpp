#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    ofstream foul;
    string s;
    foul.open("sample.txt");
    cin >> s;
    foul << s;

    foul.close();

    return 0;
}
