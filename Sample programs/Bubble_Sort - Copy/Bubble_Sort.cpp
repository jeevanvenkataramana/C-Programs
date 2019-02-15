#include <iostream>
using namespace std;
void bubble_sort(int* a,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=1;j<len-i;j++)
        {
            if(a[j-1]>a[j])
            {
                int temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
        }
    }
}

int main()
{
    int a[10]={2,5,3,4,1,9,8,7,6,0};
    bubble_sort(a,10);
    for(int i=0; i<10; i++)
    {
        cout<<a[i];
    }
    return 0;
}