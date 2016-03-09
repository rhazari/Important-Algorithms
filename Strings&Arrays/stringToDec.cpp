#include <iostream>
#include <cstring>

using namespace std;

int strToDec(char* string){
	int len = strlen(string);
	int value = 0, k = 0, flag = 0;
	if('-' == string[k]){
		flag = 1;
		++k;
	}
	while(k < len){
		value = value*10+(string[k]-'0');
		++k;
	}
	return (flag)? -value: value;
}

int main(){
	char s1[] = "14567";
	char s2[] = "-34784";

	cout<<strToDec(s1)<<endl;
	cout<<strToDec(s2)<<endl;

	return 0;
}