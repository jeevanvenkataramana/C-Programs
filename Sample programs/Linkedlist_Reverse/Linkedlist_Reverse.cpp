/*
 * Linkedlist_Reverse.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: jeevan venkataramana
 */

#include<iostream>
using namespace std;
struct Node
  {
     int data;
     struct Node *next;
  };

Node* Insert(Node *head,int data);
Node* Reverse(Node *head);
void Print(Node *head);
int main()
{
	Node* head = new Node;
	head = nullptr;
	int a[5]={1,2,3,4,5};
	for(int i=0; i<5; i++)
	{
		head=Insert(head, a[i]);
	}
	Print(head);
	cout<<endl<<endl<<"The linked list is reversed "<<endl;
	head=Reverse(head);
	Print(head);
	return 0;
}

Node* Reverse(Node *head)
{
    Node* prev   = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;

}

Node* Insert(Node *head,int data)
{
  // Complete this method

    Node* new_node = new Node;
    new_node->data=data;
    new_node->next = nullptr;

    if(head == nullptr)
    {
        head = new_node;
        return new_node;
    }
    else
    {
           Node* pos = new Node;
            pos = head;
           while(pos->next!=nullptr)
           {
               pos=pos->next;
            }

            pos->next=new_node;
            return head;
    }
}


void Print(Node *head)
{
	Node* temp = new Node;
	temp = head;

	cout<<endl<<"The Elements in the linked list:  ";
	while(temp!=nullptr)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"end";

	delete [] temp;
	return;
}
