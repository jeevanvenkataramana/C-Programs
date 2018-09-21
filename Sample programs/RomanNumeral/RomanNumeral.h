/*
 * RomanNumeral.h
 *
 *  Created on: Mar 21, 2018
 *      Author: jeeva
 */

/* Jeevan Venkataramana   011917477*/

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class RomanNumeral
{

private :

	string roman;			//stores roman value
	int decimal;			//stores decimal value of roman

	void to_roman();		//converts decimal value to roman
	void to_decimal();		//converts roman no to decimal

public:

	RomanNumeral();			//Default constructor
	RomanNumeral(string a);	//constructor creates a RomanNumeral object from an integer value
	RomanNumeral(int b);	//creates a RomanNumeral object from a string value

	int getDecimal();		//Returns the value stored in decimal
	string getRoman();		//Returns the value stored in roman

	friend RomanNumeral operator+(RomanNumeral a, RomanNumeral b);
	friend RomanNumeral operator-(RomanNumeral a, RomanNumeral b);
	friend RomanNumeral operator*(RomanNumeral a, RomanNumeral b);
	friend RomanNumeral operator/(RomanNumeral a, RomanNumeral b);

	friend bool operator==(RomanNumeral a, RomanNumeral b);
	friend bool operator!=(RomanNumeral a, RomanNumeral b);

	friend ostream& operator<<(ostream& output, RomanNumeral& a);
	friend istream& operator>>(istream& input, RomanNumeral& a);
};
#endif /* ROMANNUMERAL_H_ */
