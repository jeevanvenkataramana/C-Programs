/* Jeevan Venkataramana 011917477*/

#include<iostream>
#include<math.h>
#include<string>
#include<cstdlib>

#include "Calculator1.h"

void test();

using namespace std;
int main()
{
	string a;

	test();					//run test cases as given in prob statement along with my test cases


	while(1)
	{
		cout<<endl<<"Expression? ";
		cin>>a;
		if(a[0]=='.')
		{
			cout<<endl<<"Done!"<<endl;
			break;
		}
		Calculator1 cal(a);
		cal.Evaluate();
	}

	return 0;
}


void test()
{

	vector<string> test_string;
	cout<<endl<<"Type your expression below :"<<endl;
	test_string.push_back(" 42 =");
	test_string.push_back(" 2*(42 - 42e-1) =");
	test_string.push_back(" 12/(5.5*(17 + 0.00314E+3)) =");
	test_string.push_back(" 65%2 =");
	test_string.push_back(" 12/(5.5*(17 + 0.00314E+3) =");
	test_string.push_back("(((((5))))) =");
	test_string.push_back("(5)) + 2 =");
	test_string.push_back(" 5/(6 - 2*3) =");

	test_string.push_back(" ((2+3)(4+5)) =");
	test_string.push_back(" 2(4+5) =");
	test_string.push_back(" (2+3)(4+5)/(8+9-1)(4*5) =");
	test_string.push_back(" (2+3)(4+5)/((8+9-1)(4*5)) =");
	test_string.push_back(" (2+3)/(1-1/1) =");
	test_string.push_back(" (.03e+2+300.00e-2) =");
	test_string.push_back(" ((5 =3)=");
	test_string.push_back(" (5*9) ");

	for(unsigned int i=0; i<test_string.size();i++)
	{
		cout<<endl<<"Expression?"<<test_string[i];
		Calculator1 cal(test_string[i]);
		cal.Evaluate();
	}
}
