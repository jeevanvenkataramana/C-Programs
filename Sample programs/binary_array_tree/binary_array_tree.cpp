#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;

string solution(vector<int> arr)
{
	int left_sum = arr[0], right_sum=arr[0];
	int index =0;
	for(int i=1; i<arr.size(); i++)
	{

		for(int j=i; (j<arr.size() && j<(i+pow(2,index))); j++)
		{
			left_sum = left_sum+1;
		}
	}
return "Left";
}




int main()
{
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(6);
	arr.push_back(2);
	arr.push_back(9);
	arr.push_back(-1);
	arr.push_back(10);
	cout<<endl<<solution(arr);

}
