#include <iostream>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

int main(){
   map<char, char> m1;
   m1['('] = ')';
   m1['{'] = '}';
   m1['['] = ']';

   char str[] = "[{}]]()[{()}]";
   
   stack<char> s1;
   int length, k, valid = 1;
   char temp;

   length = strlen(str);
   for(k = 0; k < length; ++k){
      if(m1[str[k]]){
         s1.push(m1[str[k]]);
      }
      else{
         if(s1.empty()){
            valid = 0;
            break;
         }
         temp = s1.top();
         s1.pop();
         if(temp != str[k]){
            valid = 0;
            break;
         }
      }
   }

   if(valid){
      cout<<"String is a valid parantheses"<<endl;
   }
   else{
      cout<<"String is not a valid parantheses"<<endl;
   }
   return 0;
}
