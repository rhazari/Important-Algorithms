#include <iostream>
#include <vector>

using namespace std;

#define ROW 4
#define COL 3

int main(){

	int **arr = new int *[ROW];
	int j, k, val = 1;

	for(k = 0; k < ROW; ++k){
		arr[k] = new int[COL];
		for(j = 0; j < COL; ++j){
			arr[k][j] = val;
			val++; 
		}
	}

	cout<<"Original Matrix..."<<endl;
	for(k = 0; k < ROW; ++k){
		for(j = 0; j < COL; ++j){
			cout<<arr[k][j]<<"\t";
		}
		cout<<endl;
	}

	vector<int> vec;
	int row, col;
	row = ROW; col = COL;
	int x = 0, y = 0;
	while(row > 0 && col > 0){
		if(row == 1){
			for(j = 0; j < col; ++j){
				vec.push_back(arr[x][y++]);
			}
			break;
		}
		else if(col == 1){
			for(j = 0; j < row; ++j){
				vec.push_back(arr[x++][y]);
			}
			break;
		}

		for(k = 0; k < col-1; ++k){
			vec.push_back(arr[x][y++]);
		}

		for(k = 0; k < row-1; ++k){
			vec.push_back(arr[x++][y]);
		}

		for(k = 0; k < col-1; ++k){
			vec.push_back(arr[x][y--]);
		}

		for(k = 0; k < row-1; ++k){
			vec.push_back(arr[x--][y]);
		}
		++x; ++y;
		row -= 2; col -= 2;
	}

	cout<<endl;
	cout<<"Spiral Matrix..."<<endl;
	x = 0;
	for(j = 0; j < ROW; ++j){
		for(k = 0; k < COL; ++k){
			cout<<vec[x++]<<"\t";
		}
		cout<<endl;
	}

	return 0;
}