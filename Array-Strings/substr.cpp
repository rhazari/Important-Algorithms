#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

bool isSubString(char *str1, char* str2){
   int len1, len2;
   len1 = strlen(str1);
   len2 = strlen(str2);
   int count;

   char* ptr1, *ptr2;   
   while(*str1){
      if(*str1 == *str2){
         ptr1 = str1;
         ptr2 = str2;
         count = 0;
         while(*ptr1 == *ptr2){
            ptr1++;
            ptr2++;
            count++;
         }
         if(len2 == count){
            return true;
         }
      }
      str1++;
   }
   return false;
}

int main(){
   char str1[] = "raihan hazarika";
   //cout<<str1<<endl;
   char str2[] = "hazak";

   if(isSubString(str1,str2)){
      cout<<"Is a substring"<<endl;
   }
   else{
      cout<<"Not a substring"<<endl;
   }
   return 0;
}
