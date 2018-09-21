/* Jeevan Venkataramana 011917477*/

#include "Calculator1.h"
using namespace std;

Calculator1::Calculator1(string a) : exp(a)
{
	result =0;
}

void Calculator1::Evaluate()
{
	try								//include calculation in try block
	{
		remove_space();
		rem_exponents();
		if(check())
		{
			expression();
			exp = exp.substr(0,exp.length()-1);			//remove = from exp
        		result = stod(factor(exp));				//evaluate the simplified expression
			print();
		}
	}

	catch(DividebyZero a)							//catch block for possible error statements
	{
		cout<<endl<<a.get_message()<<endl;
	}

	catch(Missing a)
        {
                cout<<endl<<a.get_message()<<endl;
        }

        catch(Unexpected a)
        {
                cout<<endl<<a.get_message()<<endl;
        }
}



bool Calculator1::check()
{
	int opencount = 0;
	int closecount = 0;

	for(int i=0; i<exp.length(); i++)
	{
		if(i==exp.length()-1)
                {
                        if(exp[i]!='=')
                        {
                                throw Missing("=");
                        }
                        if(opencount!=closecount)
                        {
				throw Missing(")");
                        }
			return true;
                }

		if(exp[i]!='.'&&exp[i]!='('&&exp[i]!=')'&&(!isdigit(exp[i]))&&exp[i]!='e'&&exp[i]!='E'&&exp[i]!='+'&&exp[i]!='-'&&exp[i]!='*'&&exp[i]!='/')
		{
			throw Unexpected(exp.substr(i,1));
		}

		if(exp[i]=='(')
		{
			opencount++;
		}
		if(exp[i]==')')
		{
			closecount++;
		}

		if(closecount>opencount)
		{
			throw Unexpected(exp.substr(i,1));
		}
	}
}


void Calculator1::remove_space()					//remove spaces from the expression
{
	string a;
	for(int i=0; i<exp.length();i++)
	{
		if(exp[i] != ' ')
		{
			a=a+exp[i];
		}
	}
	exp = a;
}


void Calculator1::rem_exponents()				//remove all exponential terms in expression
{
	for(int i=0; i<exp.length(); i++)
	{
		if(exp[i]=='e'||exp[i]=='E')
		{
			string num;
			for(int j=i-1; j>=0;j--)
			{
				if(isdigit(exp[j]) || exp[j]=='.')
				{
					num = exp.substr(j,1)+num;
				}
				else
				{
					break;
				}
			}

			string power=exp.substr(i+1,1);
			for(int j=i+2;j<exp.length();j++)
			{
				if(isdigit(exp[j]))
				{
					power = power+exp.substr(j,1);
				}
				else
				{
					break;
				}
			}

			double a = stod(num);
			double b= stod(power);
			string fvalue = to_string(a*pow(10,b));

			int tlength = num.length()+power.length()+1;
			exp.insert(i-num.length(), fvalue);
			exp.erase(i+fvalue.length()-num.length(), tlength);
			return(rem_exponents());					//call recursively untill all exponential terms are simplified
		}
	}
}


void Calculator1::expression()								//extract all sub expressions
{
	for(int i=0; i<exp.length(); i++)
	{
		if(exp[i]=='(')
		{
			break;
		}
		if(exp[i]=='=')return;
	}

	int pos = 0;
	int len = 1;
	string temp;
	for(int i=0; i<exp.length(); i++)
	{
		if(exp[i]=='(')
		{
			pos = i;
			len = 0;
		}
		len++;
		if(exp[i]==')')
		{
			if(pos!=0 && isdigit(exp[pos-1]))
			{
				exp.insert(pos,"*");
				pos++;
			}

			temp=term((exp.substr(pos, len)));				//evaluate all sub expressions
			break;
		}
	}
	exp.erase(pos,len);
	exp.insert(pos,temp);								//replace the simplified sub expression with its value

	expression();		//call recursively untill all subexpressions are evaluated.
}

string Calculator1::term(string a)
{
	int len = a.length();
	return(factor(a.substr(1,len-2)));
}



string Calculator1::factor(string a)				//evaluate the sub expression sent
{
	string lhs, rhs;

	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='*'||a[i]=='/')
		{
			for(int j=i-1;j>=0;j--)
			{
				if(a[j]=='+'||a[j]=='-'||a[j]=='/'||a[j]=='*')
				{
					lhs = a.substr(j+1,i-(j+1));				//exctract lhs of operator
					break;
				}
				if(j==0)
				{
					lhs = a.substr(0,i);
				}
			}
			for(int j=i+1;j<a.length();j++)
                        {
                                if(a[j]=='+'||a[j]=='-'||a[j]=='/'||a[j]=='*')
                                {
                                        rhs = a.substr(i+1,j-(i+1));
					break;
                                }
                                if(j==a.length()-1)
                                {
                                        rhs = a.substr(i+1,a.length()-(i+1));
				}
                        }

			string ans = operate(lhs,rhs,a.substr(i,1));
			int tlength = lhs.length()+rhs.length()+1;
			a.insert(i-lhs.length(), ans);
			a.erase(i+ans.length()-lhs.length(), tlength);
			return(factor(a));						//call recursively untill all * and / operations are done on subexpression
		}
	}


	for(int i=0;i<a.length();i++)							//after evaluating * and /   evaluate + and - if present
        {
                if(a[i]=='+'||a[i]=='-')
                {
                        for(int j=i-1;j>=0;j--)
                        {
                                if(a[j]=='+'||a[j]=='-'||a[j]=='/'||a[j]=='*')
                                {
                                        lhs = a.substr(j+1,i-(j+1));
                                        break;
                                }
                                if(j==0)
                                {
                                        lhs = a.substr(0,i);
                                }
                        }
			for(int j=i+1;j<a.length();j++)
                        {
                                if(a[j]=='+'||a[j]=='-'||a[j]=='/'||a[j]=='*')
                                {
                                        rhs = a.substr(i+1,j-(i+1));
                                        break;
                                }
                                if(j==a.length()-1)
                                {
                                        rhs = a.substr(i+1,a.length()-(i+1));
                                }
                        }

                        string ans = operate(lhs,rhs,a.substr(i,1));
                        int tlength = lhs.length()+rhs.length()+1;
                        a.insert(i-lhs.length(), ans);
                        a.erase(i+ans.length()-lhs.length(), tlength);
			return(factor(a));
		}
	}
return a;
}


string Calculator1::operate(string lhs, string rhs, string opr)		//perform the operation with the given operator
{
        double num1 = stod(lhs);
        double num2 = stod(rhs);
        double ans;

	if(num2==0) throw DividebyZero("Zero");

        if(opr[0]=='+') ans=num1 + num2;
        if(opr[0]=='-') ans=num1 - num2;
        if(opr[0]=='*') ans=num1 * num2;
        if(opr[0]=='/') ans=num1 / num2;

        return(to_string(ans));

}



void Calculator1::print()
{
	cout<<endl<<result<<endl;

}


Missing::Missing(string a):message("***** Missing " + a)
{
}

string Missing::get_message()
{
	return message;
}

Unexpected::Unexpected(string a):message("***** Unexpected " + a)
{
}

string Unexpected::get_message()
{
        return message;
}

DividebyZero::DividebyZero(string a):message("***** Division by " + a)
{
}

string DividebyZero::get_message()
{
        return message;
}
