// Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
// For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”]

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {0, 1, 3, 27, 50, 75};
    nums.push_back(100);
    int index;
    index = 0;
    int len = nums.size();
    string result = "";
    while(index < len){
        while(index+1 < len && nums[index]+1 == nums[index+1]){
            ++index;
        }
        string str = "";
        if(nums[index] - nums[index-1] == 2){
            str = to_string(nums[index]-1);
        }
        else if (nums[index] - nums[index-1] > 2){
            str = to_string(nums[index-1]+1) + "->"+to_string(nums[index]-1);
        }
        cout<<str<<"\n";
        result += str;
        result += str.size() > 0 ? ", ":"";
        ++index;
    }
    cout<<result<<"\n";
}