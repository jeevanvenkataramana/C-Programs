/*
 * Linkedlist_InsertNPos.cpp
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
Node* InsertNth(Node *head, int data, int position);
void Print(Node *head);
int main()
{
	int n;
	Node* head = new Node;
	head = nullptr;
	int a[5]={1,2,3,4,5};
	for(int i=0; i<5; i++)
	{
		head=Insert(head, a[i]);
	}
	Print(head);
	cout<<endl<<endl<<"Enter the element to be inserted:";
	cin>>n;
	int pos;
	cout<<endl<<"Enter the position the data needs to be inserted:";
	cin>>pos;
	head=InsertNth(head,n,pos);
	Print(head);
	return 0;
}

Node* InsertNth(Node *head, int data, int position)
{

    Node* new_node = new Node;
    new_node->data = data;
    new_node->next=nullptr;

    if(head==nullptr)
    {
        head=new_node;
        return head;
    }
    else if(position==0)
    {
        new_node->next = head;
        head = new_node;
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
        if(pos->next==nullptr)
        {
            pos->next=new_node;
        }
        else
        {
            Node* temp = new Node;
            temp = pos;
            new_node->next=temp->next;
            temp->next=new_node;
        }
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

