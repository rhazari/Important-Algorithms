// Word Count Frequency from a text file

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main(){
    string fileName = "Guwahati.txt";
    fstream fs(fileName);

    unordered_map<string, int> mp;
    string word;
    while(fs >> word){
        if(!mp.count(word)){
            mp[word] = 1;
        }
        else{
            mp[word]++;
        }
    }
    fs.close();

    for(const auto& elem: mp){
        cout <<elem.first<<" "<<elem.second<<"\n";
    }
    cout<<"\n";
}