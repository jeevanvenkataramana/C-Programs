/*
 * SelectionSortApp.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: jeeva
 */


#include <iostream>
using namespace std;
void selection_sort(int* a,int len)
{
    for(int i=0;i<len-1;i++)
    {   
        int temp=a[i];
        int index=i;
        for(int j=i+1;j<len; j++)
        {
            if(a[j]<a[index])
            {
                index=j;
            }
        }
        a[i]=a[index];
        a[index]=temp;
    }
}

int main()
{
    int a[10]={2,5,3,4,1,9,8,7,6,0};
    selection_sort(a,10);
    for(int i=0; i<10; i++)
    {
        cout<<a[i];
    }
    return 0;
}