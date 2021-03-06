/*
 * Linkedlist_Delete.cpp
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
Node* Delete(Node *head, int position);
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
	int pos;
	cout<<endl<<endl<<"Enter the position the data needs to be removed:";
	cin>>pos;
	head=Delete(head,pos);
	Print(head);
	return 0;
}

Node* Delete(Node *head, int position)
{

    if(position==0)
    {
        Node* new_node = new Node;
        new_node = head;
        head = head->next;
        delete new_node;
        return head;

    }
    else
    {
        Node* pos = new Node;
        pos = head;
        for(int i=0; i<position-1; i++)
        {
            pos=pos->next;
        }
        Node* temp = new Node;
        temp = pos->next;
        pos->next = temp->next;
        delete temp;
        return head;

    }
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

	cout<<endl<<"The elements in the linked list:  ";
	while(temp!=nullptr)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"end";

	delete [] temp;
	return;
}


