/*
 * RomanNumeral.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: jeeva
 */

/* Jeevan Venkataramana 011917477*/

#include "RomanNumeral.h"
using namespace std;

RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{

}

RomanNumeral::RomanNumeral(string a)            //default constructor for roman number
{
	roman = a;
	decimal=0;
}

RomanNumeral::RomanNumeral(int b)               //default constructor for storing decimal value
{
	decimal = b;
}

int RomanNumeral::getDecimal()                  //get function calls function that converts roman to decimal
{
	to_decimal();
	return decimal;
}

string RomanNumeral:: getRoman()                //get Roman value ; calls function that converts decimal to roman
{
	to_roman();
	return roman;
}

void RomanNumeral::to_roman()
{
	vector<string> thousands{"","M","MM","MMM"};             //considering it doesnt cross 3999
	vector<string> hundreds{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	vector<string> tens{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	vector<string> ones{"","I","II","III","IV","V","VI","VII","VIII","IX"};

	int value = decimal;
	int i;
	string roman1;

	if(value)                           //take ones place of decimal value and get its roman value
	{
		i = value%10;
		roman1 = ones[i] + roman1;
		value=value/10;
	}

	if(value)                           //take tens place of decimal value and get its roman value
	{
		i = value%10;
		roman1 = tens[i] + roman1;
		value=value/10;
	}

	if(value)                        //take hundreds place of decimal value and get its roman value
	{
		i = value%10;
		roman1 = hundreds[i] + roman1;
		value=value/10;
	}

	if(value)                        //take thousand place of decimal value and get its roman value
	{
		i = value%10;
		roman1 = thousands[i] + roman1;
		value=value/10;
	}

	roman = roman1;

}

void RomanNumeral::to_decimal()
{
	vector<string> thousands{"","M","MM","MMM"};
	vector<string> hundreds{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	vector<string> tens{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	vector<string> ones{"","I","II","III","IV","V","VI","VII","VIII","IX"};

	string s = roman;
	int i = 0;
	int value = 0;

	while(s[i] == 'M')                     //scan unit u get thousands equivalent from roman value
	{
		i++;
	}
	value = i * 1000;



	int pos = i;
	while((s[i] =='C')|(s[i]=='D')|(s[i]=='M'))        //scan unit u get hundreds equivalents from roman value
	{
		i++;
	}

	string temp = s.substr(pos,i-pos);                 //extract the roman numeral which contains 100,s equivalent

	int j = 0;
	while(hundreds[j] != temp)
	{
		j++;
	}
	value += j*100;



	pos = i;
	while((s[i] == 'X')|(s[i]=='L')|(s[i]=='C'))
	{
		i++;
	}

	temp = s.substr(pos,i-pos);

	j = 0;
	while(tens[j] != temp)
	{
		j++;
	}
	value += j*10;




	pos = i;
	while((s[i] == 'V')|(s[i] == 'I')|(s[i]=='X'))
	{
		i++;
	}

	temp = s.substr(pos,i-pos);

	j = 0;
	while(ones[j] != temp)
	{
		j++;
	}
	value += j;


	decimal = value;
}

RomanNumeral operator+(RomanNumeral a, RomanNumeral b)
{
	RomanNumeral sum;
	sum.decimal = a.getDecimal() + b.getDecimal();
	sum.roman = sum.getRoman();
	return sum;
}

RomanNumeral operator-(RomanNumeral a, RomanNumeral b)
{
	RomanNumeral diff;
	diff.decimal = a.getDecimal() - b.getDecimal();
	diff.roman = diff.getRoman();
	return diff;
}

RomanNumeral operator*(RomanNumeral a, RomanNumeral b)
{
	RomanNumeral mul;
	mul.decimal = a.getDecimal() * b.getDecimal();
	mul.roman = mul.getRoman();
	return mul;
}

RomanNumeral operator/(RomanNumeral a, RomanNumeral b)
{
	RomanNumeral div;
	div.decimal = a.getDecimal() / b.getDecimal();
	div.roman = div.getRoman();
	return div;
}

bool operator==(RomanNumeral a, RomanNumeral b)
{
	return(a.getDecimal() == b.getDecimal());
}

bool operator!=(RomanNumeral a, RomanNumeral b)
{
	return(a.getDecimal() != b.getDecimal());
}


ostream& operator<<(ostream& output, RomanNumeral& a)
{
   if(a.roman=="")                        //if roman equivalent not present then get
	{
		a.roman = a.getRoman();
	}
	else if(a.decimal)                     //if roman equivalent not present then get
	{
		a.decimal = a.getDecimal();
	}
	else
	{
		a.decimal = a.getDecimal();
		a.roman = a.getRoman();
	}
	output<<"["<<a.decimal<<":"<<a.roman<<"]";
	return output;
}


istream &operator>>(istream &input, RomanNumeral& a)
{
	input>>a.roman;
	return input;
}



/***** Complete this class implementation. *****/
