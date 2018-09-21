/* Jeevan Venkataramana 011917477*/

#ifndef BOOKLIST_H_
#define BOOKLIST_H_

#include<iostream>
#include<vector>
#include <iomanip>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;
#include "BookNode.h"
#include "Book.h"
/**
 * A list of book nodes.
 */
class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);

    /**
     * Print the list.
     */
    void print();                         //print the books in the list

    void Insert(Book b);                  //inserting the book in to the correct position in the list

    void sortbyName();                          //sorting according to the required author

    bool duplicate(Book b);





    /***** Complete this class. *****/

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes

};

#endif /* BOOKLIST_H_ */
