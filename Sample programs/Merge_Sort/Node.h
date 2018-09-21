/*
 * Node.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jeeva
 */

#ifndef NODE_H_
#define NODE_H_

#include<iostream>

class Node
{
	public:

	Node();
	Node(int a);
	~Node();

	public:

		int data;
		Node *next;

};
#endif

