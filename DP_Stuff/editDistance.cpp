#include <iostream>
#include <vector>

using namespace std;

void computeDistance(string s1, string s2){
	int sz1, sz2;
	sz1 = s1.size(); sz2 = s2.size();
	vector<vector<int> > vec(sz1+1, vector<int>(sz2+1,0));
	int j, k;
	for(j = 0; j <= sz1; ++j){
		vec[j][0] = j;
	}
	for(k = 0; k <= sz2; ++k){
		vec[0][k] = k;
	}

	for(j = 0; j < sz1; ++j){
		for(k = 0; k < sz2; ++k){
			if(s1[j] == s2[k]){
				vec[j+1][k+1] = vec[j][k];
			}
			else{
				int mn = min(vec[j+1][k],vec[j][k]);
				mn = min(mn,vec[j][k+1]);
				vec[j+1][k+1] = mn+1;
			}
		}
	}
	cout<<"Min edits needed to covert "<<s1<<"->"<<s2<<": "<<vec[sz1][sz2]<<endl;

}

int main(){
	string s1("abcdef");
	string s2("azced");

	computeDistance(s1, s2);

	return 0;
}
