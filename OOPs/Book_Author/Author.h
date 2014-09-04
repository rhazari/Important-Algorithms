#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

using namespace std;

class Author
{
   private:
   string name;
   string email;
   char gender;

   public:
   Author(string name, string email, char gender);
   string getName() const;
   string getEmail() const;
   void setEmail(string email);
   char getGender() const;
   void print() const;
};

#endif

