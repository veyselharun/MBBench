/*
 * Pollard Rho Algorithm
 * File: pollard.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <time.h>
int gcd(int number1 , int number2 )
{ 
   
  int dividing=0,gcd=1;
  if(number1<=number2)
  {
     dividing=number1;
  }else
  {
     dividing=number2;
  }
  
  for( int i=2 ;i <= dividing; i++ )
  {
    
      if( number1 % i == 0 && number2 % i ==0 )
      {
        
         gcd=i;    
      }
  }
  
  return gcd; 
}
int pollard(int n)
{
  int i=1;
 
  srand(time(NULL));
 
  int x=rand()%(n-1);

  int y=x;
  int k=2;
  int d=1;
  int pow=0;
 
  while(true)
  {
    i=i+1;
    pow=x*x;
    x= (pow-1)%n;
    
    d= gcd( abs(y-x) ,n);
   
    if(d!=1 && d!=n)
    {
       return d;
    }
   
    if(i==k)
    {
      y=x;
      k=2*k;
    }
  }
}
int main(int argc,char * argv[])
{
  
  int n= atoi( * ( argv + 1) );
 
  int result= pollard(n);
 
  return(0);
}