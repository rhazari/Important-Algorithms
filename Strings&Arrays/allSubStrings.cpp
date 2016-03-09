#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void SubString(string str){
	int length = str.length();
	cout<<"Total SubString for "<<str<<": "<<length*(length+1)/2<<endl;
	int x, y;
	for(x = 1; x <= length; ++x){
		for(y = 0; y <= length-x; ++y){
			cout<<str.substr(y,x)<<"\t";
		}
		cout<<endl;
	}

}

void subString(const char *string){
	int length = strlen(string);
	cout<<"Total SubString for "<<string<<": "<<length*(length+1)/2<<endl;
	int x, y;
	while(*string){
		for(x = 0; x <length; ++x){
			for(y = 0; y <= x; ++y){
				cout<<*(string+y);
			}
			cout<<" ";
		}
		--length;
		cout<<endl;
		++string;	
	}	
}

int main(){
	SubString("raihan");
	cout<<endl;
	subString("travis");
	return 0;
}
