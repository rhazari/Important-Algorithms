// Number of Lines in a File

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    int number_of_lines = 0;
    string line;
    fstream myfile("Guwahati.txt");

    while (getline(myfile, line))
        ++number_of_lines;
    cout << "Number of lines in text file: " << number_of_lines<<"\n";
}