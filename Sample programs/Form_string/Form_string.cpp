/* Created by Jeevan Venkataramana */

/* Problem find the count of min no of times string A must be repeated so that string b is the substring of count times string A. */

#include<iostream>
#include<string>
using namespace std;
string ch_substring(string, string);
int main()
{

	cout<<"string 1: abc     string 2: dabcdabc     Result:"<<ch_substring("abc","dabcdabc")<<endl;
	cout<<"string 1: abcd     string 2: cdabcdab     Result:"<<ch_substring("abcd","cdabcdab")<<endl;
	cout<<"string 1: abcd     string 2: abcdabcd     Result:"<<ch_substring("abcd","abcdabcd")<<endl;
	cout<<"string 1: abcd     string 2: cdabcdabcd     Result:"<<ch_substring("abcd","cdabcdabcd")<<endl;
	cout<<"string 1: abcd     string 2: abcdabcdab     Result:"<<ch_substring("abcd","abcdabcdab")<<endl;
	cout<<"string 1: abcd     string 2: ababcdabcd     Result:"<<ch_substring("abcd","ababcdabcd")<<endl;
	cout<<"string 1: abcd     string 2: abcdabcda     Result:"<<ch_substring("abcd","abcdabcda")<<endl;
	cout<<"string 1: ccac     string 2: cacccacc     Result:"<<ch_substring("ccac","cacccacc")<<endl;
	cout<<"string 1: cacc     string 2: cccacccacc     Result:"<<ch_substring("cacc","cccacccacc")<<endl;
	cout<<"string 1: ccac     string 2: cccacccacc     Result:"<<ch_substring("ccac","cccacccacc")<<endl;
	return 0;
}

string ch_substring(string a, string b)
{
	int pos;
	unsigned int i=0;
	string twice_a = a+a;
	for(i=0; i<a.length();i++)
	{
		if(b[0]==a[i] && (twice_a.substr(i,a.length()) == b.substr(0,a.length())))			//to find position from where the string repeats and also check if the string flowing is a repetition.
		{
			pos=i;
			break;
		}
	}
	int count=b.length()/a.length();
	string temp="";
	unsigned int min_length=pos+b.length();
	for(int i=0; i<count+2; i++)
	{
		temp=temp+a;
		if(min_length <= temp.length())
		{
			if(b==temp.substr(pos,b.length()))
				return(to_string(i+1) + " , "+temp);
		}
	}
	return(to_string(-1) + " , Impossible");
}
