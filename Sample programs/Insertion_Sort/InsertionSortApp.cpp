/*
 * InsertionSortApp.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: jeeva
 */

#include<iostream>

using namespace std;
int main()
{
	int n;
	cout<<endl<<"Enter no of elements : ";
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	for(int i=0; i<n; i++)
	{
		int j=i;
		while(j-1>=0)
		{
			if(a[j]<a[j-1])
			{
				int temp = a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
			else
			{
				break;
			}
			j--;
		}
	}
	cout<<endl<<" Elements after Insertion sort "<<endl<<endl;
	for(int i=0; i<n; i++)
		{
			cout<<a[i]<<"\t";
		}


	return 0;
}

