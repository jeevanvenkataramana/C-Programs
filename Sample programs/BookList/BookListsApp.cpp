/*
 * BookListsApp.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: jeeva
 */

/* Jeevan Venkataramana 011917477*/

#include "Book.h"
#include "BookList.h"
#include "BookNode.h"
#include<iostream>
#include<vector>
#include <iomanip>
#include <fstream>
#include <string>
#include<cstring>

using namespace std;

const string CATEGORIES_FILE_NAME = "categories.txt";

void listBooks(string a);              //listing book of a certain category or all
void SortbyAuthor(string a);           // list book of authors of certain letter range

int main()
{
   ifstream input;
   input.open(CATEGORIES_FILE_NAME);

   if (input.fail())
   {
      cout << "Failed to open " << CATEGORIES_FILE_NAME << endl;
      return -1;
   }

   vector < string > category_files;

   string command;
   input>>command;

    while (!input.fail())
   {
      listBooks(command);
      input >> command;
   }

   listBooks("MERGED");                         //get all the books in different categories sorted
   SortbyAuthor("AUTHORS A-M");                 //get the list of books of a specific author
   SortbyAuthor("AUTHORS N_Z");

  input.close();

   return 0;
}



void listBooks(string category)
{
   ifstream ins;
   BookList list(category);

   if(category != "MERGED")               //if it has to be listed of certain category   else all
   {
      BookList list(category);

      string file_name = category+".txt";             //getting the filename of a certain category
      ins.open(file_name);

      if (ins.fail())
      {
         cout << "Failed to open category file" << file_name << endl;
         return;
      }

      Book a;
      ins>>a;

      while (!ins.fail())
      {
         list.Insert(a);
         ins>>a;
      }
      list.print();
   }
   else
   {

      string file_name = CATEGORIES_FILE_NAME;

      ins.open(file_name);


      if (ins.fail())
      {
         cout << "Failed to open category file" << file_name << endl;
         return;
      }

      string a;
      ins>>a;

      ifstream ins2;                   //ins to read the categories ; ins2 to read books of certain categories pointed by ins


      while (!ins.fail())
      {
         string cat_file_name = a+".txt";



         ins2.open(cat_file_name);

         if (ins2.fail())
         {
            cout << "Failed to open category file" << file_name << endl;
            return;
         }

         Book book;
         ins2>>book;


         while (!ins2.fail())
         {
            list.Insert(book);
            ins2>>book;
         }

         ins2.close();

         ins>>a;
      }

      list.print();
   }

}


void SortbyAuthor(string Author_Range)
{
   ifstream ins;
   BookList list(Author_Range);

   string file_name = CATEGORIES_FILE_NAME;

   ins.open(file_name);


   if (ins.fail())
   {
      cout << "Failed to open category file" << CATEGORIES_FILE_NAME << endl;
      return;
   }

   string a;
   ins>>a;

   ifstream ins2;


   while (!ins.fail())
   {
      string cat_file_name = a+".txt";


      ins2.open(cat_file_name);

      if (ins2.fail())
      {
         cout << "Failed to open category file" << file_name << endl;
         return;
      }

      Book book;
      ins2>>book;


      while (!ins2.fail())
      {
         list.Insert(book);
         ins2>>book;
      }

      ins2.close();

      ins>>a;
   }

  list.sortbyName();                      //sort list according to the range
   list.print();



}


