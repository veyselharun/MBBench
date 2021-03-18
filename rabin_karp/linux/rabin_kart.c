/*
 * Rabin Kart Algorithm
 * File: rabin_kart.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int strong(int base,int power)
{
    int strong_result= 1;
    for( int k= 0; k < power ; k++ )
    {

       strong_result=strong_result * base;
    }
   return strong_result;
}
int main(int argc,char * argv[])
{
  int number_of_characters; 
  
  number_of_characters= atoi( *( argv + 1 ) );
  
  char sentence[number_of_characters];
  char sentence2[number_of_characters];

  strcpy(sentence, *(argv+2) );
  strcpy(sentence2, *(argv+3) );

  int number_of_letters= strlen(sentence);
  int dimension= number_of_letters;
  int hash= 0;
  int hash_sum= 0;
 
  for( int i= number_of_letters-1 ; i >= 0; i-- )
  {
      hash= sentence[i] * strong(3,i);
      hash_sum= hash_sum + hash;
  }
  number_of_letters= strlen(sentence2);
  hash= 0;
  hash_sum= 0;
  
  for( int i=number_of_letters-1 ; i>=0 ; i-- )
  {
      hash= sentence2[i] * strong(3,i);
      hash_sum= hash_sum + hash;
  }
  int wanted= hash_sum;
  hash= 0;
  hash_sum= 0;
  char array[number_of_letters];
  int position= 0;
  int number= 0;
  for( int  i= 0; i < dimension ; i++ )
  {
     
     for( int j= position ; j < dimension ; j++ )
     {
           if( number <= number_of_letters )
           {
            array[number]= sentence[j];
            number++;
           }
     }
     position++;
     number= 0;
    
     for( int j= number_of_letters - 1 ; j >= 0 ; j-- )
     {
   
      hash= array[j] * strong(3,j);
      hash_sum= hash_sum + hash;
     }
   
     if( hash_sum == wanted )
     {
      
       
     }
     hash=0;
     hash_sum=0;
  }
  
  return(0);
}