/*
 * Bit_Change.cpp
 *
 *  Created on: May 31, 2018
 *      Author: jeevan venkataramana
 */
#include<iostream>
#include<string>
int similar_bits(char a, char b);

using namespace std;

int main()
{
string a, b;
cout<<endl<<"enter key 1: ";
cin>>a;
cout<<endl<<"enter key 2: ";
cin>>b;
int n= a.length();
int count=0;
for(int i=0; i<n; i++)
{

	count += similar_bits(a[i],b[i]);
}
cout<<endl<<" No of bits similar : "<<count;
return 0;
}

int similar_bits(char a, char b)
{
	int x,y;

	if(a=='0')x=0;
	if(a=='1')x=1;
	if(a=='2')x=2;
	if(a=='3')x=3;
	if(a=='4')x=4;
	if(a=='5')x=5;
	if(a=='6')x=6;
	if(a=='7')x=7;
	if(a=='8')x=8;
	if(a=='9')x=9;
	if(a=='a')x=10;
	if(a=='b')x=11;
	if(a=='c')x=12;
	if(a=='d')x=13;
	if(a=='e')x=14;
	if(a=='f')x=15;
	if(b=='0')y=0;
	if(b=='1')y=1;
	if(b=='2')y=2;
	if(b=='3')y=3;
	if(b=='4')y=4;
	if(b=='5')y=5;
	if(b=='6')y=6;
	if(b=='7')y=7;
	if(b=='8')y=8;
	if(b=='9')y=9;
	if(b=='a')y=10;
	if(b=='b')y=11;
	if(b=='c')y=12;
	if(b=='d')y=13;
	if(b=='e')y=14;
	if(b=='f')y=15;

	int xor_result = x^y;
	int result=0;
	for(int i=0; i<4; i++)
	{
		if(xor_result % 2 == 0)
		{
			result++;
		}
		xor_result = xor_result/2;
	}
	return result;
}
