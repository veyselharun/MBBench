/*
 * Greatest Common Divisor for Two Numbers
 * File: gcd.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
 
  int number1= 0,number2= 0;  
 
  number1=atoi(*(argv+1));
  number2=atoi(*(argv+2));

  int dividing=0,gcd=1;
  if(number1<=number2)
  {
     dividing=number1;
  }else
  {
     dividing=number2;
  }
 
  for(int i=2 ;i <= dividing; i++)
  {
     
      if( number1 % i == 0 && number2 % i ==0 )
      {
         
         gcd=i;    
      }
  }
  
  if(gcd==1)
  {
    
  }else
  {
    
  }
  return(0);
}