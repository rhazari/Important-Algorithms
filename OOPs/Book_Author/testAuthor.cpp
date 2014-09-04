#include "Author.h"
 
int main() 
{
   Author peter("Peter Jones", "peter@somewhere.com", 'm');
   peter.print();
   
   peter.setEmail("peter@xyz.com");
   peter.print();
 
   Author paul("Paul Jones", "@somewhere.com", 'n');
   paul.setEmail("paul@");
   paul.print();
   
   return 0;
}
