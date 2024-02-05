#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string firstName, lastName;
    
    cout << "Welcome to CS 280 in Spring 2023 Semester\nPlease enter your first name\n";
    cin >> firstName;
    
    cout << "Please enter your last name\n";
    cin >> lastName;

    cout << "Welcome " <<firstName << " " << lastName << " to CS280\n";

    return 0;
}
