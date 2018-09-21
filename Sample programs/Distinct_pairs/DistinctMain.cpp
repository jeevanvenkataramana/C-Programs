/*
 * Main.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: jeeva
 */
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, count=0;
	cin>>n;
	cout<<endl;
	int a[n];
	for(int i=0;i<n; i++)
	{
		cin>>a[i];
	}
	int target;
	cin>>target;

	vector<int> unique;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(a[i]+a[j]==target)
			{
				count++;
				if(unique.size()==0)
				{
					unique.push_back(a[i]);
					unique.push_back(a[j]);

				}else
				{
				for(unsigned int z=0; z<unique.size(); z++)
				{
					if(a[i]==unique[z] && a[j] == unique[z+1])
					{
						count--;
						break;
					}
					if(a[j]==unique[z] && a[i] == unique[z+1])
					{
						count--;
						break;
					}

					if(z==(unique.size()-2))
					{
						unique.push_back(a[i]);
						unique.push_back(a[j]);
					}
					z++;

				}
				}

			}
			}
		}

	cout<<endl<<"Count :"<<count<<endl;
	return 0;
}





