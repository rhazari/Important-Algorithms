#include <iostream>

#define N 3
using namespace std;


int main(){

	int **arr = new int *[N];
	int j, k, value = 1;
	for(j = 0; j < N; ++j){
		arr[j] = new int[N];
		for(k = 0; k < N; ++k){
			arr[j][k] = value++;
		}
	}

	//Original Matrix
	for(j = 0; j < N; ++j){
		for(k = 0; k < N; ++k){
			cout<<arr[j][k]<<"\t";
		}
		cout<<endl;
	}

	//Rotate Matrix
	int layer, first, last, offset;
	for(layer = 0; layer < N/2; ++layer){
		first = layer;
		last = N - 1 - first;
		for(k = first; k < last; ++k){
			offset = k - first;
			int top = arr[first][k];

			arr[first][k] = arr[last-offset][first];

			arr[last-offset][first] = arr[last][last-offset];

			arr[last][last-offset] = arr[k][last];

			arr[k][last] = top;
		}
	}

	cout<<"After rotating the matrix..."<<endl;
	for(j = 0; j < N; ++j){
		for(k = 0; k < N; ++k){
			cout<<arr[j][k]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
