/* Created by Jeevan Venkataramana */

#include<iostream>
#include<string>

const int ROW_SIZE = 5;			//take the no of names as input, set column size to some length
const int COL_SIZE = 5;
const int MAX_LENGTH = 100;

void print(char names[ROW_SIZE][COL_SIZE]);		//valid

void print_n(char names[][COL_SIZE], int n);	//valid

void print_f(char** names, int n);

using namespace std;

int main()
{

	int n;
	char s[ROW_SIZE][COL_SIZE];
	cout<<"Enter no of elements: ";
	cin>>n;
	for(int i=0; i<ROW_SIZE; i++)
	{
		cin>>s[i];
	}

	print(s);
	print_n(s,n);


	int count=0;
	cout<<endl<<"Input elements for dynamic array :";
	cin>>count;
	char** list;
	list = new char*[count];

	for(int i=0; i<count; i++)
	{
		list[i] = new char[MAX_LENGTH];
		cin>>list[i];
	}

	print_f(list,count);

for(int i=0; i<count; i++)
delete[] list[i];
delete[] list;
return 0;
}


void print(char names[ROW_SIZE][COL_SIZE])
{
	cout<<endl<<"Printing through function "<<endl;
		for(int i=0; i<ROW_SIZE; i++)
		{
			cout<<names[i]<<endl;
		}
}

void print_n(char names[][COL_SIZE], int n)
{
	cout<<endl<<"Printing through function by passing n and specifying column size"<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<names[i]<<endl;
		}
}


void print_f(char **names,int n)
{
	cout<<endl<<"Printing through function by passing n and dynamic array"<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<names[i]<<endl;
		}
}
