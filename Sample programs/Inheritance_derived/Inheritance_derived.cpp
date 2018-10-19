/*
 * Inheritance_derived.cpp
 *
 *  Created on: Oct 19, 2018
 *      Author: jeevan venkataramana
 */




#include<iostream>

using namespace std;

class person
{
public:
	string name;
public:
	person(string name)
	{
		this->name=name;
	}

};


class student: public person
{
public:
	int id;
public:
student(string name, int id):person(name)
{
	this->name=name;
	this->id=id;
}

void print()
{
	cout<<"Name :"<<name<<"  id "<<id<<endl;
}
};

int main()
{
	student a("jeevan",37);
	a.print();
}
