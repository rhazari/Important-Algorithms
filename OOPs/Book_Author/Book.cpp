#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(string name, Author author, double price, int qty): name(name), author(author){
   setPrice(price);
   setQty(qty);
}

string Book::getName() const
{
   return name;
}

Author Book::getAuthor() const
{
   return author;
}

double Book::getPrice() const
{
   return price;
}

void Book::setPrice(double price)
{
   if(price > 0)
   {
      this->price = price;
   }
   else
   {
      cout<<"Price should be postive!!!"<<endl;
      this->price = 0;
   } 
}

int Book::getQty() const
{
   return qty;
}

void Book::setQty(int qty)
{
   if(qty >= 0)
   {
      this->qty = qty;
   }
   else
   {
      cout <<"Quantity cannot be negative"<<endl;
      this->qty = 0;
   }
}

void Book::print() const
{
   cout << "'" << name << "' by ";
   author.print();
}

string Book::getAuthorName() const
{
   return author.getName();
}
