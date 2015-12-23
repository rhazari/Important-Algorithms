#include <iostream>
#include <cstring>
#include <map>

using namespace std;

bool isIsomorphic(char* str1, char* str2){
   map<char, char> m1;
   int len1, len2;
   len1 = strlen(str1);
   len2 = strlen(str2);
   if(len1 != len2){
      return false;
   }
   int k;
   for(k = 0; k < len1; k++){
      m1[str1[k]] = str2[k];
   }

   for(k = 0; k < len1; k++){
      if(m1[str1[k]] != str2[k]){
         return false;
      }
   }
   return true;
}

int main(){
   char str1[] = "foo";
   char str2[] = "bar";

   if(isIsomorphic(str1,str2)){
      cout<<"Strings are iso-morphic"<<endl;
   }
   else {
      cout<<"Strings are not iso-morphic"<<endl;
   }

   return 0;
}

