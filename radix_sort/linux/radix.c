/*
 * Radix Sort Algorithm
 * File: radix.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main( int argc , char * argv[] )
{
  
  int number_count= atoi(*(argv+1));

  int * numbers,*numbers_copy;

  numbers= malloc(sizeof(int)*number_count);
  numbers_copy= malloc(sizeof(int)*number_count);

  int indices= 0;

  for( int i= 2 ; i < argc ; i++ )
  {

     numbers[indices]= atoi (* ( argv + i ) );

     indices++;
  }

  indices=0;

  int units_digit[number_count];
  for( int k=0 ; k < number_count ; k++ )
  {

    units_digit[k]= numbers[k]%10;
  } 

  int most_greatest= 0;

  int place=0;
  for(int k= 0 ; k < number_count ; k++ )
  {

     most_greatest= 0;

     for( int j=0 ; j < number_count ; j++ )
     {
       if( units_digit[j] >= most_greatest )
       {
          most_greatest= units_digit[j];
          place= j;
       }
     }  

     numbers_copy[k]= numbers[place];

     units_digit[place]= -1;
     numbers[place]= -1;
   }

   indices=0;

   for(int k=number_count-1 ; k >= 0 ; k-- )
   {
     numbers[indices]= numbers_copy[k];

     indices++;
   } 

   for( int k=0 ; k < number_count ; k++ )
   {

     units_digit[k]= numbers[k] % 100;

     units_digit[k]= units_digit[k] / 10;
   } 

   most_greatest= 0;

   place=0;
   for( int k= 0 ; k < number_count ; k++ )
   {

     most_greatest= 0;

     for( int j= 0 ; j < number_count ; j++ )
     {
       if(units_digit[j] >= most_greatest )
       {
          most_greatest= units_digit[j];
          place= j;
       }
     }  

     numbers_copy[k]=numbers[place];

     units_digit[place]= -1;
     numbers[place]= -1;
   }

   indices=0;

   for( int k= number_count-1; k >=0 ; k-- )
   {

     numbers[indices]= numbers_copy[k];

     indices++;
   } 

   for( int k= 0 ; k < number_count ; k++ )
   {
     units_digit[k]= numbers[k] / 100;
   } 

   most_greatest= 0;

   place=0;
   for( int k= 0 ; k < number_count ; k++ )
   {

     most_greatest= 0;

     for( int  j=0 ; j < number_count ; j++)
     {
       if( units_digit[j] >= most_greatest )
       {
          most_greatest= units_digit[j];
          place= j;
       }
     }  

     numbers_copy[k]=numbers[place];

     units_digit[place]= -1;
     numbers[place]= -1;
   }
   
   indices=0;
  
   for( int k= number_count-1 ; k >= 0 ; k-- )
   {
     numbers[indices]= numbers_copy[k];
     indices++;
   } 
   
   return(0);
}