/* Jeevan Venkataramana 011917477*/

#include "Book.h"
#include <string>
#include <iomanip>

using namespace std;

Book::Book()
{
}

Book::Book(string isbn, string last, string first, string title)
{
   this->isbn = isbn;
   this->last = last;
  this->first = first;
   this->title = title;
}

string Book::getIsbn() const
{
   return isbn;
}

string Book::getLast() const
{
   return last;
}

string Book::getFirst() const
{
   return first;
}

string Book::getTitle() const
{
   return title;
}

ostream& operator<<(ostream& output, Book& a)
{
   output<<"Book{ISBN="<<a.isbn<<", last="<<a.last<<", first="<<a.first;
   output<<", title="<<a.title<<"}"<<endl;
   return output;
}


istream& operator >>(istream &input, Book& book)
{
   string a;
   getline(input, a);
   int pos = 0, count = 0;

   for(unsigned int i = 0; i< a.length(); i++)
   {
      if(a[i] == ',')
      {
         count++;                                  //keeps a count of how many data menbers are set
         if(count == 1)
         {
            book.isbn = a.substr(pos,i);
            pos = i+1;
         }
         if(count == 2)
         {
            book.last = a.substr(pos,i-pos);
            pos = i+1;

         }
         if(count == 3)
         {
            book.first = a.substr(pos,i-pos);
            pos = i+1;
            book.title = a.substr(pos,a.length()-pos);         //extracting title
         }

      }
   }

   return input;
}


Book::~Book()
{

}/*
 * Book.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: jeeva
 */




