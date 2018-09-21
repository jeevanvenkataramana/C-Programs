/*
 * PrimeSpirals.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: jeeva
 */
/* Jeevan Venkataramana   SID 011917477  */

#include <iostream>
#include<iomanip>
#include<vector>
#include<cstring>
#include <string>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number
const int MAX_NUMBER = 10255;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing



/***** Complete this program. *****/

void do_prime_spiral(const int n, const int start);
void print_spiral(const int n, const int start, vector<vector<char>> a);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);
}


void do_prime_spiral(const int n, const int start)
{

   vector<vector<char>> a(MAX_SIZE, vector<char>(MAX_SIZE));      //declaring a 2D vector

   //checking the size and starting value conditions

   if((n%2==0)|(n>101)|(start>50)|(start<1))
   {
      print_spiral(n, start, a);
      return;
   }

   //prime no code


   int num[MAX_NUMBER];             //stores primes and non primes as zero
   int initial_prime=2;             //initializing prime and then to next subsequent no leaving 0
   int i, j;                        //for looping
   int flag = 1;                    //flag for indicating search of primes has ended

   for(i=0; i<MAX_NUMBER;i++)
   {
      num[i] = i+2;
   }

   int product;                      //for generating multiples of next subsequent no

   while(flag!=0)                   /*flag will be zero only in the case if there are no subsequent numbers*/
   {
   	i = 1;
   	product=0;

      while(product<=MAX_NUMBER)
      {
         product = initial_prime * i;                 /*generate product terms of initial_primes*/

         for(int j=initial_prime-1; j<MAX_NUMBER; j++)
         {
            if(product == num[j])                     /*if product matches with any of the digits below the range make it 0*/
            {
               num[j]=0;
               break;
            }
         }
         i++;
      }
	   flag = 0;                                    /*flag will be zero only in the case if there are no subsequent numbers*/

      for(i= initial_prime-1;i<MAX_NUMBER;i++)
      {
         if(num[i]!=0)                             /* searching for next prime which wasnt a zero or multiple of prev primes*/
         {
            flag=1;                                /*flag will be one only in the case if there is a subsequent no to be checked */
			   initial_prime = num[i];
            break;
         }
	   }

   }


   //representing prime no positions with # and the rest with a .

   vector<char> v(MAX_NUMBER+1);                //will have . for non prime positions and # for prime no positions
   for (unsigned int k = 0; k < v.size( ); k++)
   {
      if(k==0)
      {
         v[k] = '.';                            //initializing 1 as prime
      }
      if(num[k-1]>0)
      {
         v[k] = '#';                            //if no present then it is prime so represent as #
      }
      else
      {
         v[k] = '.';
      }
   }


   // spiral code with vector index equal to starting value start-1

   int mid, row, col, count;

   j=8;                       //spiral will be genearte no as multiples of 8

   mid = n/2;
   int value = start-1;                  //initialize vector position to starting value
   a[mid][mid] = v[value];
   value++;
   row = mid;
   col = mid;


   while(j<=(mid*8))                      //repeats untill matrix if filled
   {
      col ++;
      a[row][col] = v[value];          //initializing 1st value of next spiral
      value++;
      flag = j/4;                         //flag stores the no of values needed for each side of spiral
      count = 1;

      while(count<flag)
      {
         row --;
         a[row][col] = v[value];
         value++;
         count++;
      }

      while(count<2 * flag)
      {
         col --;
         a[row][col] = v[value];
         value++;
         count++;
      }

      while(count<3 * flag)
      {
         row ++;
         a[row][col] = v[value];
         value++;
         count++;
      }

      while(count<4 * flag)
      {
         col ++;
         a[row][col] = v[value];
         value++;
         count++;
      }

      j= j+8;                          //spiral size increases as a multiple of 8
   }

   print_spiral( n, start, a);

}





void print_spiral(const int n, const int start, vector<vector<char>> a)
{

   if(n%2==0)
   {
      cout<<"Prime spiral of size "<<n<<" starting at "<<start;
      cout<<"\n***** Error: Size "<<n<<" must be odd.\n\n";
      return;

   }
   if(n>101)
   {
      cout<<"Prime spiral of size "<<n<<" starting at "<<start;
      cout<<"\n***** Error: Size "<<n<<" must be 101 or below.\n\n";
      return;
   }

   if((start>50)|(start<1))
   {
      cout<<"Prime spiral of size "<<n<<" starting at "<<start;
      cout<<"\n***** Error: Starting value  0 < 1 or > 50\n\n";
      return;

   }

   cout<<"Prime spiral of size "<<n<<" starting at "<<start<<"\n";
   for(int i=0;i<n;i++)
   {
       cout<<"\n ";
      for(int j=0; j<n; j++)
      {
         cout<<a[i][j];
      }
   }
   cout<<"\n\n";


}
