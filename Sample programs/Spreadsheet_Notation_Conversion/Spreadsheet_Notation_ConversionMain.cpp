/*
 * Spreadsheet_Notation_ConversionMain.cpp
 *
 *  Created on: Jul 21, 2018
 *      Author: jeevan venkataramana
 */

#include<iostream>
using namespace std;
string conversion(int n);
int main()
{
	/* Test Cases */
	cout<<"Label for no 701: "<<conversion(701)<<endl;
	cout<<"Label for no 702: "<<conversion(702)<<endl;
	cout<<"Label for no 703: "<<conversion(703)<<endl;
	cout<<"Label for no 1413: "<<conversion(1413)<<endl;
	cout<<"Label for no 56: "<<conversion(56)<<endl;
	cout<<"Label for no 26: "<<conversion(26)<<endl;
	cout<<"Label for no 27: "<<conversion(27)<<endl;
	cout<<"Label for no 15457: "<<conversion(15457)<<endl;
	cout<<"Label for no 30891: "<<conversion(30891)<<endl;
	return 0;
}

string conversion(int n)
{
	char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};;
	int row_no=n/702;
	if(n%702!=0)row_no++;	//increment when not a multiple of 702
	int temp=n/702;
	int temp2= n - (temp*702);	//offset in the particular row
	string col_name;

	if(temp2<=26)
	{
		if(temp2==0)col_name="ZZ";	//last no of rows
		else
		{
			col_name=alpha[temp2-1];
		}
	}
	else
	{
		int temp3=temp2/26;
		int temp4=temp2%26;
		col_name=alpha[temp3-1];
		col_name=col_name+alpha[temp4-1];
	}
	return(to_string(row_no)+col_name);

}


