#ifndef CALCULATOR1_H_
#define CALCULATOR1_H_

#include<iostream>
#include<vector>
#include<string>
#include<exception>
#include<math.h>
#include<stdexcept>

using namespace std;

class Calculator1
{
	private :
		string exp;
		double result;

	public :
		Calculator1(string a);
		void Evaluate();
		bool check();
		void remove_space();
		void rem_exponents();
		void expression();
		string term(string a);
		string factor(string a);
		string operate(string lhs, string rhs, string opr);
		void print();
};

class Missing
{
	private:
		string message;

	public:

		Missing(string a);
		string get_message();
};

class Unexpected
{

	private:
		string message;

	public:

		Unexpected(string a);
		string get_message();
};

class DividebyZero
{

	private:
		string message;

	public:

		DividebyZero(string a);
		string get_message();
};

#endif
