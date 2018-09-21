/*
 * List.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: jeeva
 */

#include<iostream>
#include"List.h"

List::List()
{
	head = nullptr;
}


void List::Insert(int a)
{
	Node* new_node = new Node;
	new_node->data = a;

	if(head==nullptr)
	{
		head = new_node;
		return;
	}

	if(head->next == nullptr)
	{
		head->next = new_node;
		return;
	}

	Node* temp = new Node;
	temp = head;
	while(temp->next!=nullptr)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	return;
}
void List::View()
{
	if(head==nullptr)
	{
		cout<<endl<<"Nothing to View"<<endl;
		return;
	}
	else
	{
		Node* temp = new Node;
		temp = head;
		cout<<endl<<"The elements in the list :"<<endl;
		while(temp!=nullptr)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	}

	return;
}

void List::Sort()
{

}

int List::Size()
{
	Node* temp = new Node;
	temp = head;
	int count=0;
	if(head==nullptr)return 0;

	while(temp!=nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
