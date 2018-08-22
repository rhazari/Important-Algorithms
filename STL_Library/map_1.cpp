#include <iostream>
#include <string>
#include <utility>
#include <map>

using namespace std;

void display(map<string, int> dis_map)
{
    map<string, int>::iterator itr;
    for(itr = dis_map.begin(); itr != dis_map.end(); itr++)
    {
        cout<<itr->first<<": "<<itr->second<<"\n";
    }
}

int main()
{
    typedef map<string, int> map_type;
    map_type populationMap;    
    
    populationMap.insert(make_pair("China",1339));
    populationMap.insert(make_pair("India",1187));
    populationMap.insert(make_pair("US",310));
    populationMap.insert(make_pair("Indonesia",234));
    populationMap.insert(make_pair("Brazil",193));
    populationMap.insert(make_pair("Pakistan",170));

    map_type:: iterator itr = --populationMap.end();
    populationMap.erase(itr);
    cout<<"Size of the population map: "<<populationMap.size()<<"\n";

    display(populationMap);

    string country = "Indonesia";
    itr = populationMap.find(country);
    if(itr != populationMap.end())
    {
        cout<<country<<" population is: "<<itr->second<<"\n";
    }
    else
    {
        cout<<"Country not in map"<<"\n";
    }

    return 0;
}
