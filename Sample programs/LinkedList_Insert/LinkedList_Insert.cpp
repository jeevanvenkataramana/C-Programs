/*
 * LinkedList_Insert.cpp
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
void Print(Node *head);
int main()
{
	int n;
	cout<<endl<<"Enter no of elements:";
	cin>>n;
	Node* head = new Node;
	head = nullptr;
	int a[n];
	cout<<endl<<"Enter elements:"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		head=Insert(head, a[i]);
	}

	Print(head);
	return 0;
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




