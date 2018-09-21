/*
 * Book.h
 *
 *  Created on: Mar 15, 2018
 *      Author: jeeva
 */


/* Jeevan Venkataramana 011917477*/

#ifndef BOOK_H_
#define BOOK_H_

#include<iostream>
#include<vector>
#include <iomanip>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;

class Book
{
public:

   Book();

   Book(string isbn, string last, string first, string title);

   string getIsbn() const;                      //return Isbn of book

    string getLast() const;                     //return Last name of book

    string getFirst() const;                    //return First of book

    string getTitle() const;                    //return Title of book

    friend ostream& operator<<(ostream& output, Book& a);

	friend istream& operator >> (istream&  input, Book& a);

	~Book();

private:

   string isbn;
   string last;
   string first;
   string title;

};

#endif /* BOOK_H_ */

