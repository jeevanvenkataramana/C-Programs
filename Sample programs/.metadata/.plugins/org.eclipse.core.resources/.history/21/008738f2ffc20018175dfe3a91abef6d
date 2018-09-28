/*
 * Insert_atHead.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: jeevan venkataramana
 */

#include<iostream>
#include"Insert_element.cpp"
using namespace std;
Node* Insert2(Node *head,int data);
void Print2(Node *head);

int main2()
{
	int n;
	Node* head = new Node;
	head = nullptr;
	int a[5]={1,2,3,4,5};

	for(int i=0; i<5; i++)
	{
		head=Insert2(head, a[i]);
	}

	Print2(head);
	return 0;
}

Node* Insert2(Node *head,int data)
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


void Print2(Node *head)
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



