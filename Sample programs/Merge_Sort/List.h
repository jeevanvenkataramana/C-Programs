/*
 * List.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jeeva
 */



#ifndef LIST_H_
#define LIST_H_

#include<iostream>
#include"Node.h"
using namespace std;

class List
{
public:

	List();
	void Insert(int a);
	void View();
	void Sort();
	int Size();

	public:

		Node* head;

};
#endif


