/*
 * DFS.cpp
 *
 *  Created on: Oct 13, 2018
 *      Author: jeevan venkataramana
 */


#include<iostream>
#include<vector>
using namespace std;
struct Node
{
	int value;
	Node* parent;
	Node* left_child;
	Node* right_child;
	bool visited;
};

Node* dfs(Node* node, int target)
{
	cout<<node->value;
	node->visited=true;

	if(node->value == target)
	{
		return node;
	}

	Node* nodes[3]={node->right_child, node->parent, node->left_child};

	for(int i=0; i<3; i++)
	{
		if(nodes[i] && !nodes[i]->visited)
		{
			Node* result=dfs(nodes[i],target);
			if(result)
			{
				return result;
			}
		}
	}
return nullptr;
}

int main()
{
	cout<<"i am here";
	Node* temp1= new Node;
	Node* temp2= new Node;
	Node* temp3= new Node;
	Node* temp4= new Node;
	Node* temp5= new Node;
	Node* temp6= new Node;
	Node* temp7= new Node;
	Node* temp8= new Node;
	Node* temp9= new Node;
	Node* temp10= new Node;
	Node* temp11= new Node;
	Node* temp12= new Node;
	Node* temp13= new Node;
	Node* temp14= new Node;
	Node* temp15= new Node;

	temp1->value=5;
	temp1->left_child=temp2;
	temp1->right_child=temp10;

	temp2->value=4;
	temp2->left_child=temp3;
	temp2->right_child=temp6;
	temp2->parent=temp1;

	temp3->value=7;
	temp3->left_child=temp4;
	temp3->right_child=temp5;
	temp3->parent=temp2;

	temp4->value=8;
	temp4->parent=temp3;

	temp5->value=1;
	temp5->parent=temp3;

	temp6->value=3;
	temp6->right_child=temp7;
	temp6->parent=temp2;

	temp7->value=9;
	temp7->left_child=temp8;
	temp7->parent=temp6;

	temp8->value=2;
	temp8->right_child=temp9;
	temp8->parent=temp7;


	temp9->value=12;
	temp9->parent=temp8;

	temp10->value=1;
	temp10->left_child=temp11;
	temp10->parent=temp1;

	temp11->value=8;
	temp11->left_child=temp12;
	temp11->right_child=temp15;
	temp11->parent=temp10;

	temp12->value=11;
	temp12->left_child=temp13;
	temp12->right_child=temp14;
	temp12->parent=temp11;

	temp13->value=4;
	temp13->parent=temp12;

	temp14->value=5;
	temp14->parent=temp12;

	temp15->value=5;
	temp15->parent=temp11;

	Node* ans=dfs(temp11,12);
	cout<<ans->value;

	delete temp1;
	delete temp2;
	delete temp3;
	delete temp4;
	delete temp5;
	delete temp6;
	delete temp7;
	delete temp8;
	delete temp9;
	delete temp10;
	delete temp11;
	delete temp12;
	delete temp13;
	delete temp14;
	delete temp15;
	delete ans;
	return 0;

}