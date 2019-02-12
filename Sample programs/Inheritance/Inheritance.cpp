/*
 * Inheritance.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: jeevan venkataramana
 */

#include<iostream>
using namespace std;
class person
{
public:
	void activity()
	{
		cout<<"Eat and sleep"<<endl;
	}
};


class student: public person
{
public:
	void study()
	{
		cout<<"Eat and study"<<endl;
	}

	// an example of overriding the definition
	void activity()
	{
		cout<<"Eat sleep and study";
	}
};

int main()
{
	student a;
	a.study();
	a.activity();

}
