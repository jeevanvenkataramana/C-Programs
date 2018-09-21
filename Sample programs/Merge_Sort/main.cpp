/*
 * main.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: jeeva
 */

#include<iostream>
#include<string>
#include"Node.h"
#include"List.h"

using namespace std;
 int main()
 {
	 int n;
	 cin>>n;
	 List list;

	 cout<<endl<<"Enter the elements :"<<endl;
	 for(int i=0;i<n;i++)
	 {
		 int a;
		 cin>>a;
		 list.Insert(a);
	 }

	 list.View();
	// list.Sort();
	 cout<<endl<<"List after merge sort :"<<endl;
	 list.View();

 }



