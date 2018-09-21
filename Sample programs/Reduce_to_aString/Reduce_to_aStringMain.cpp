/*
 *  Created on: Jun 11, 2018
 *      Author: jeevan venkataramana


Problem statement: Given a string S and T, returns the count of characters that need to be deleted from S to form string T.
otherwise 0.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool match_present(string a, string b)
{
	if(a.length()==b.length())
	{
		if(a==b) return true;
		else return false;
	}

	unsigned int j=0;
	for(unsigned int i=0; i<b.length(); i++)
	{
		if(b[i]==a[j])
		{
			if(i==b.length()-1) return true;	//if all characters of string b are matched then return true.
		}
		else
		{
			i--;
			if(j==a.length()-1) return false;	//if the all characters of string a re searched but still string b is not possible make string b.
		}
		j++;
	}
return false;
}

int solution(string s, string t)
{
	int slen = s.length();
	int tlen = t.length();
	if(tlen > slen) return 0;
	vector<int> index;				//note down the index of occurrence of first character of T in S

	signed int i=0;

	while(i<(slen - tlen + 1))
	{
		if(s[i]==t[0])
		{
			index.push_back(i);
		}
		i++;
	}

	for(unsigned i=0; i<index.size(); i++)
	{
		if(match_present(s.substr(index[i], slen-i), t))
		{
			return(slen-tlen);  		//return 1 based on question.
		}
	}
	return 0;
}

int main()
{
	cout<<"ab"<<"  "<<"ba  ";
	cout<<solution("ab","ba")<<endl;
	cout<<"venjeevan"<<"  "<<"jeevan  ";
	cout<<solution("venjeevan","jeevan")<<endl;
	cout<<"venjeeezvan"<<"  "<<"jeevan  ";
	cout<<solution("venjeeezvan","jeevan")<<endl;
	cout<<"venjeeezvanan"<<"  "<<"jeevan  ";
	cout<<solution("venjeeezvanan","jeevan")<<endl;
	cout<<"venjeeeaaaaaaazvanan"<<"  "<<"jeevan  ";
	cout<<solution("venjeeeaaaaaaazvanan","jeevan")<<endl;
	return 0;
}


