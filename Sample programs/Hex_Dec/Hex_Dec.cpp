/* Created by Jeevan Venkataramana */

#include<iostream>
#include<string>
int to_decimal(char a);
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
	int x= to_decimal(a[i]);
	int y= to_decimal(b[i]);
	int xor_result = x^y;

	for(int j=0; j<4; j++)
	{
		if(xor_result % 2 == 0)
		{
			count++;
		}
		xor_result = xor_result/2;
	}
}
cout<<endl<<" No of bits similar : "<<count;
return 0;
}

int to_decimal(char a)
{
	if(a=='0')return 0;
	if(a=='1')return 1;
	if(a=='2') return 2;
	if(a=='3') return 3;
	if(a=='4') return 4;
	if(a=='5') return 5;
	if(a=='6') return 6;
	if(a=='7') return 7;
	if(a=='8') return 8;
	if(a=='9') return 9;
	if(a=='a') return 10;
	if(a=='b') return 11;
	if(a=='c') return 12;
	if(a=='d') return 13;
	if(a=='e') return 14;
	if(a=='f') return 15;

	return -1;
}
