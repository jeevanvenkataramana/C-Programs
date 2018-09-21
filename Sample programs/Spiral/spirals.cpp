/*
 * spirals.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: jeeva
 */

/* Jeevan Venkataramana   SID 011917477  */

#include <iostream>
#include<iomanip>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void do_spiral(const int n, const int start);
void print_spiral(const int n, const int start, int a[MAX_SIZE][MAX_SIZE]);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
   return 0;


}


void do_spiral(const int n, const int start)
{
   int a[MAX_SIZE][MAX_SIZE];
   if((n%2==0)|(n>101)|(start>50)|(start<1))
   {
      print_spiral(n, start, a);
      return;
   }

   int j=8, mid, row, col, flag, count;

   mid = n/2;
   int value = start;                  /*initializing starting value to the middle of matrix*/
   a[mid][mid] = value++;
   row = mid;
   col = mid;


   while(j<=(mid*8))                      /*repeats untill matrix if filled*/
   {
      col ++;
      a[row][col] = value++;              /*initializing 1st value of next spiral*/

      flag = j/4;                         /*flag stores the no of values needed for each side of spiral*/
      count = 1;

      while(count<flag)
      {
         row --;
         a[row][col] = value++;
         count++;
      }

      while(count<2 * flag)
      {
         col --;
         a[row][col] = value++;
         count++;
      }

      while(count<3 * flag)
      {
         row ++;
         a[row][col] = value++;
         count++;
      }

      while(count<4 * flag)
      {
         col ++;
         a[row][col] = value++;
         count++;
      }

      j= j+8;                          /*spiral size increases as a multiple of 8*/
   }

   print_spiral( n, start, a);

}


void print_spiral(const int n, const int start, int a[MAX_SIZE][MAX_SIZE])
{
   if(n%2==0)
   {
      cout<<"Spiral of size "<<n<<" starting at "<<start;
      cout<<"\n***** Error: Size "<<n<<" must be odd.\n\n";
      return;

   }
   if(n>101)
   {
      cout<<"Spiral of size "<<n<<" starting at "<<start;
      cout<<"\n***** Error: Size "<<n<<" must be 101 or below.\n\n";
      return;
   }

   if((start>50)|(start<1))
   {
      cout<<"Spiral of size "<<n<<" starting at "<<start;
      cout<<"\n***** Error: Starting value "<<start<<" must be between 1 and 50. \n\n";
      return;

   }

   cout<<"Spiral of size "<<n<<" starting at "<<start<<"\n";
   for(int i=0;i<n;i++)
   {
       cout<<"\n ";
      for(int j=0; j<n; j++)
      {
         cout<<a[i][j]<<setw(4);
      }
   }
   cout<<"\n\n";
}
