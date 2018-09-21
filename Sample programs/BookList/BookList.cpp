/*
 * BookList.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: jeeva
 */



/* Jeevan Venkataramana 011917477*/

#include"BookList.h"
#include"Book.h"

BookList::BookList(const string name)
    : name(name), head(nullptr), tail(nullptr)
{

}


void BookList::print()
{
   BookNode *p = head;
   int i=0;
   cout<<endl<<"Book list: "<<name<<endl<<endl;

   while(p != nullptr)
    {
      cout<<"  ";
      cout<<p->book;                         //print until end of list
      p = p->next;
      i++;
    }
    cout<<"    ("<<i<<" books)"<<endl;
}


void BookList::Insert(Book b)
{
   BookNode *a, *first = head;            // a is a booknode ptr for the book that has to be inserted
   a = new BookNode;
   a->book = b;

   if(head == nullptr)                    //if no book in the list add book and mark it as head
   {
      head = a;
      head->next = nullptr;
      return;
   }
   else if ((head->book.getIsbn() > b.getIsbn()) && (duplicate(b)))        //if the book has to be inserted at the beginning
   {
      a->next = first;
      head = a;
      return;
   }
   else if(duplicate(b))
   {
      while(first!= nullptr)
      {
         if(first->book.getIsbn() < b.getIsbn())                           //if isbn of book is greater than head and a subsequent one
         {
               if(first->next != nullptr)
               {
                  if(first->next->book.getIsbn() > b.getIsbn())               //to check whether the book isbn is lesser than the subsequent one
                  {
                     a->next = first -> next;
                     first->next = a;
                     return;
                  }
               }
               else
               {
                  a->next = nullptr;                                       // adding at the end of list
                  first->next = a;
                  return;
               }
         }
         first = first->next;
      }
   }
}


void BookList :: sortbyName()
{
   string first_letter = name.substr(8,1);               //trace the letters range for sorting the list accordingly
   string last_letter = name.substr(10,1);
   BookNode *p = head;
   BookNode *prev = nullptr;
   int flag = 0;
   while(p != nullptr)
   {
      string a = p->book.getLast();
      a = a.substr(0,1);
      flag = 0;
      if(first_letter > a || last_letter < a)               //the book p is pointing has to be removed from the list
      {
         if(p->book.getIsbn() == head->book.getIsbn())
         {
            head = p->next;
         }
         else
         {
            flag = 1;
            prev->next = p->next;
         }
      }
      if(flag == 0)                                      //prev has to be retained if book was removed
      {
         prev=p;

      }


      p = p->next;

   }

}

bool BookList::duplicate(Book b)                         // to check if a book of similar ISBN was added before
{
   BookNode *d = head;

   while(d != nullptr)
   {
      if(b.getIsbn() == d->book.getIsbn())
      {
         return 0;
      }
      d = d->next;

   }
   return 1;

}
