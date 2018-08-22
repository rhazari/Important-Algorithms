#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    const string delims(" ,.;'");
    map<string, int> words;
    string line, str;

    ifstream myfile("stairways_heaven.txt", ios_base::in);
    while(getline(myfile,line))
    {
        string::size_type beg, end;
        beg = line.find_first_not_of(delims);
        while(beg != string::npos)
        {
            end = line.find_first_of(delims,beg);
            if (end == string::npos)
            {
                end = line.length();    
            }
            str.assign(line,beg,end-beg+1);
            ++words[str];
            beg = line.find_first_not_of(delims,end);
        }
    }

    map<string, int>::const_iterator itr;
    for(itr = words.begin(); itr != words.end(); itr++)
    {
        cout<<itr->first<<" : "<<itr->second<<"\n";
    }

    myfile.close();
    return 0;
}
