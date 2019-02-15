/*
 * InsertionSortApp.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: jeeva
 */


#include <iostream>
using namespace std;
void insertion_sort(int* a,int len)
{
    for(int i=1;i<len;i++)
    {       
        int j=i-1;
        int key=a[i];
        while( a[j]>key && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int a[10]={2,5,3,4,1,9,8,7,6,0};
    insertion_sort(a,10);
    for(int i=0; i<10; i++)
    {
        cout<<a[i];
    }
    return 0;
}