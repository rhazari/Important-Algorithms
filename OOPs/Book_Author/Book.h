#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"

using namespace std;

class Book
{
   private:
   string name;
   Author author;
   double price;
   int qty;

   public:
   Book(string name, Author author, double price, int qty=0);
   string getName() const;
   Author getAuthor() const;
   double getPrice() const;
   void setPrice(double price);
   int getQty() const;
   void setQty(int qty);
   void print() const;
   string getAuthorName() const;
   
};

#endif



