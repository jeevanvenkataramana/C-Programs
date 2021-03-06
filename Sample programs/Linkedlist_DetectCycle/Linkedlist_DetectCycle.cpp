/*
 * Linkedlist_DetectCycle.cpp
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
bool has_cycle(Node* head);
int main()
{
	Node* head = new Node;
	head = nullptr;
	int a[5]={1,2,3,4,5};
	for(int i=0; i<5; i++)
	{
		head=Insert(head, a[i]);
	}
	cout<<endl<<"Linked List created without cycle"<<endl;
	Print(head);
	cout<<endl<<endl<<"Do we have a cycle:"<<has_cycle(head);
	cout<<endl<<endl<<"Linked List modified with a cycle 5 to 2"<<endl;
	Node* temp = new Node;
	Node* temp2 = new Node;
	temp=head;
	temp2=head;
	temp=temp->next; // maps to 2
	while(temp2->next!=nullptr)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
	Print(head);
	cout<<endl<<endl<<"Do we have a cycle:"<<has_cycle(head);

	return 0;
}

bool has_cycle(Node* head) {
    if(head==nullptr)return false;
    unordered_set<Node*> temp;
    Node* temp1=head;
    while(temp1!=nullptr)
    {
        if(temp.find(temp1)!=temp.end())
        {
            return true;
        }
        temp.insert(temp1);
        temp1=temp1->next;
    }
    return false;
}








bool has_cycle(Node* head) {

	if(head==nullptr)return false;
    Node* temp= new Node;
    temp = head;
    int i=0;
    while(i<101)         //or length of the linked list
    {
     if(temp==nullptr)
     {
         return false;
     }
        else temp=temp->next;
        i++;


    }
    return true;
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
	int count=0;
	cout<<endl<<"The Elements in the linked list:  ";
	while(temp!=nullptr && count<20)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
		count++;
	}
	cout<<"end";

	delete [] temp;
	return;
}


