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
void ReversePrint(Node *head);
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
	cout<<endl<<endl<<"The linked list in reverse order: ";
	ReversePrint(head);
	return 0;
}

void ReversePrint(Node *head)
{
    int count =0;
    Node* temp = new Node;
    temp = head;
    while(temp!=nullptr)
    {
        temp=temp->next;
        count++;
    }

    while(count>0)
    {
        temp=head;
        int i= 1;
        while(i<count)
        {
            temp=temp->next;
            i++;
        }
        cout<<temp->data<<" <- ";
        count--;

    }
    cout<<"head";
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


