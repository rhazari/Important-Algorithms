#include <iostream>
#include "Author.h"

using namespace std;

Author::Author(string name, string email, char gender)
{
   this->name = name;
   setEmail(email);
   if(gender == 'm' || gender == 'f')
   {
      this->gender = gender;
   }
   else
   {
      cout<<"Invalid gender !!! Set to unknown"<<endl;
      this->gender = 'u';
   }
}

string Author::getName() const
{
   return name;
}

string Author::getEmail() const
{
   return email;
}

char Author::getGender() const
{
   return gender;
}

void Author::setEmail(string email)
{
   size_t index = email.find('@');
   if( index != string::npos && index != 0 && index != email.length()-1)
   {
      this->email = email;
   }
   else
   {
      cout<<"Invalid email !!! Set to empty"<<endl;
      this->email = " ";
   }   
}

void Author::print() const
{
   cout << name <<"( "<<gender<<" )"<<email<<endl; 
}


