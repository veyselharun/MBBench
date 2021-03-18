/*
 * Counting Sort Algorithm
 * File: counting.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main(int argc,char * argv[])
{
  
 
  int capacity= atoi(*(argv+1));
  
  int numbers[capacity];
 
  int indices=0;
  
  for( int i=2 ; i < argc ; i++ )
  {
     numbers[indices]= atoi( * ( argv+i ) );
     indices++;
  }
  indices= 0;

  int gcd=0;
 
  for( int i=0 ; i < capacity ; i++ )
  {
    if( numbers[i] > gcd )
    {
       gcd= numbers[i]; 
    }
  }
 
  int B[gcd+1];
  for( int i=0 ; i < gcd+1 ; i++ )
  {
    B[i]= 0;
  }
 
  int C[capacity];
  int number= 0,wanted= 0;
 
  for( int i=0 ; i < capacity ; i++ )
  {
     wanted= numbers[i];
     for( int j=0 ; j < capacity ; j++ )
     {
           if( wanted == numbers[j] )
           {
               number++;
           }
     }
     B[wanted]= number;
     number= 0;
  }
 
  for( int k= 0 ; k < gcd+1 ; k++ )
  {
      B[k+1]= B[k+1] + B[k];
  } 
  int location= 0;
  int new_location= 0;
  int counter= 0;
  
  for(int k=capacity - 1 ; k >= 0 ; k-- )
  { 
         location= numbers[k];
         new_location= B[location] - 1;
         C[new_location]= numbers[k]; 
  } 
 
  return(0);
}