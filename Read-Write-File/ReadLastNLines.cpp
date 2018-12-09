// Read last n lines from the file at any point without reading the entire file.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string line;
    fstream myfile("Guwahati.txt");

    int bufferLimit = 5;
    vector<string> buffer(bufferLimit,""); 

    int index = 0;
    while (getline(myfile, line)){
        buffer[index] = line;
        if(++index >= bufferLimit){
            index = 0;
        }
    }

    ofstream outFile("outFile.txt");
    
    for(int k = 0; k < bufferLimit; ++k){
        // cout<<buffer[index]<<"\n";
        outFile << buffer[index];
        if(++index >= bufferLimit){
            index = 0;
        }
    }

}