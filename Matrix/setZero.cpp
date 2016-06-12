#include <iostream>
#include <cstdlib>

using namespace std;

#define COL 4
#define ROW 5

int main(){
	int j, k;
	int **array = new int*[ROW];
	for(j = 0; j < ROW; ++j){
		array[j] = new int[COL];
		for(k = 0; k < COL; ++k){
			array[j][k] = rand()%100+1;
		}
	}

	array[2][3] = 0;
	array[0][2] = 0;

	cout<<"Original Array ..."<<endl;
	for(j = 0; j < ROW; ++j){
		for(k = 0; k < COL; ++k){
			cout<< array[j][k]<<"\t";
		}
		cout<<endl;
	}

	cout<<endl;

	bool firstRowZero = false;
	bool firstColZero = false;
	for(j = 0; j < COL; ++j){
		if(0 == array[0][j]){
			firstRowZero = true;
			break;
		}
	}

	for(j = 0; j < ROW; ++j){
		if(0 == array[j][0]){
			firstColZero = true;
			break;
		}
	}

	for(j = 0; j < ROW; ++j){
		for(k = 0; k < COL; ++k){
			if(0 == array[j][k]){
				array[j][0] = 0;
				array[0][k] = 0;
			}
		}
	}

	for(j = 1; j < ROW; ++j){
		for(k = 1; k < COL; ++k){
			if(0 == array[0][k] || 0 == array[j][0]){
				array[j][k] = 0;
			}
		}
	}

	if(firstColZero){
		for(k = 0; k < ROW; ++k){
			array[k][0] = 0;
		}
	}

	if(firstRowZero){
		for(k = 0; k < COL; ++k){
			array[0][k] = 0;
		}
	}

	cout<<"After setting zeros ..."<<endl;
	for(j = 0; j < ROW; ++j){
		for(k = 0; k < COL; ++k){
			cout<< array[j][k]<<"\t";
		}
		cout<<endl;
	}

	return 0;
}