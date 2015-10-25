#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void stockBuySell(int *array, int length){
	vector<int> buyPrices, sellPrices;
	int i = 0;
	while(i < length-1){

		while((i < length-1) && array[i+1] <= array[i]){
			++i;
		}

		if(i == length-1){
			break;
		}

		buyPrices.push_back(array[i]);

		while((i < length-1) && array[i+1] > array[i]){
			++i;
		}
		sellPrices.push_back(array[i]);
	}

	int count = min(buyPrices.size(), sellPrices.size());
	int max_profit = 0;
	for(i = 0; i < count; ++i){
		cout<<"Buy Price: "<<buyPrices[i]<<" Sell Price: "<<sellPrices[i]<<endl;
		max_profit += sellPrices[i]-buyPrices[i];
	}
	cout<<"Max Profit: "<<max_profit<<endl;

}

int main(){
	
	int stock_prices[] = {100, 180, 260, 310, 40, 535, 695};
	int length = sizeof(stock_prices)/sizeof(int);

	stockBuySell(stock_prices, length);

	return 0;
}