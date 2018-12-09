//Program to find the number of conflicting Intervals
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b) 
{
    int d = abs(a) - abs(b);
    if (d == 0)
        return a < b;   
    return d < 0;
}

struct Meeting {
    int start;
    int end;
};

int main(int argc, char**argv)
{
    Meeting allMeetings[] = {{1, 3},{2, 4},{6, 7},{4, 6}, {5, 6}};
    
    int N = sizeof(allMeetings) / sizeof(allMeetings[0]);
    
    vector<int> times;
    
    for (int i = 0; i < N; i++) {
        times.push_back(allMeetings[i].start);
        times.push_back(-allMeetings[i].end);   
    }
    
    sort(times.begin(), times.end(), compare);
    for(auto it = times.begin(); it != times.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    int rooms = 0;
    int maxRooms = 0;
    
    for (auto ii = times.begin(); ii != times.end(); ++ii) {
        if (*ii > 0) {
            // hit the meeting start time
            rooms++;
            maxRooms = max(rooms,maxRooms);
        }
        else {
            // hit the meeting end time
            rooms--;
        }
    }
    
    cout << "max number of rooms needed is " << maxRooms << endl;
}