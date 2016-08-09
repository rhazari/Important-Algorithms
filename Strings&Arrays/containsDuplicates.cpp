#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

	int arr[] = {1,2,4,3,5,7,8,5,9,-4};
	unordered_map<int, int> um;
	int k, len;
	len = sizeof(arr)/sizeof(arr[0]);
	for(k = 0; k < len; ++k){
		if(um.find(arr[k]) == um.end()){
			um[arr[k]] = k;
		}
		else{
			cout<<"Holds duplicates: "<<arr[k]<<endl;
			cout<<k - um[arr[k]]<<endl;
			break;
		}
	}
	return 0;
}
