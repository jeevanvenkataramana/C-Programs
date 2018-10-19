/*
 * Inheritance_diamond.cpp
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

/* virtual must be added else intern will have two copies of activity and might not know which one to use*/

class student: public virtual person
{
public:
	void study()
	{
		cout<<"Eat and study"<<endl;
	}

};

class employee: public virtual person
{
public:
	void work()
	{
		cout<<"Eat and work"<<endl;
	}

};

class intern: public employee, public student
{
public:
	void task()
	{
		cout<<"Eat study and work"<<endl;
	}

};

int main()
{
	intern a;
	a.activity();
	a.study();
	a.work();
	a.task();

}
