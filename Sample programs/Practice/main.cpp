/*
 * main.cpp
 *
 *  Created on: May 31, 2018
 *      Author: jeevan venkataramana
 */

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cout<<"enter no of elements:";
	cin>>n;
	vector<int> a;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}

	cout<<endl<<"2 pairs"<<endl;

	int i=0;
	while(1)
	{
		if(i+1<n)
		{
			cout<<"("<<a[i]<<","<<a[i+1]<<")  ";
		}
		else
		{
			cout<<"("<<a[i]<<","<<"0)  ";
			break;
		}
		i=i+2;
	}

	cout<<endl<<endl<<"3 pairs"<<endl;
	i=0;
	while(1)
		{

			if(i+2<n)
			{
				cout<<"("<<a[i]<<","<<a[i+1]<<","<<a[i+2]<<")  ";
			}
			else
			{
				if(i==n)
				{
					break;
				}

				if(i+1<n)
				{
					cout<<"("<<a[i]<<","<<a[i+1]<<","<<"0)  ";
				}
				else
				{
					cout<<"("<<a[i]<<",0,0)  ";
				}
				break;
			}
			i=i+3;
		}


	cout<<endl<<endl<<"4 pairs"<<endl;
		i=0;
		while(1)
			{

				if(i+3<n)
				{
					cout<<"("<<a[i]<<","<<a[i+1]<<","<<a[i+2]<<","<<a[i+3]<<")  ";
				}
				else
				{
					if(i==n)
					{
						break;
					}

					if(i+1<n)
					{
						cout<<"("<<a[i]<<","<<a[i+1]<<","<<a[i+2]<<","<<"0)  ";
					}
					else
					{
						if(i+2<n)
						{
							cout<<"("<<a[i]<<","<<a[i+1]<<","<<"0"<<","<<"0)  ";
						}
						else
						{
							cout<<"("<<a[i]<<",0,0,0)  ";
						}
					}
					break;
				}
				i=i+4;
			}


	cout<<endl<<endl<<" Interleaving"<<endl;
	cout<<"1 interleaving"<<endl;
	i=0;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+2;
	}
	cout<<endl;
	i=1;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+2;
	}

	cout<<endl<<endl<<"2 interleaving"<<endl;
	i=0;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+3;
	}
	cout<<endl;
	i=1;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+3;
	}
	cout<<endl;
	i=2;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+3;
	}



	cout<<endl<<endl<<"3 interleaving"<<endl;
	i=0;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+4;
	}
	cout<<endl;
	i=1;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+4;
	}

	cout<<endl;
	i=2;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+4;
	}
	cout<<endl;
	i=3;
	while(i<n)
	{
		cout<<a[i]<<" ";
		i=i+4;
	}

	return 0;
}


