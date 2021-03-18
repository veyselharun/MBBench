/*
 * Bucket Sort Algorithm
 * File: bucket.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
void sort( int ranking [] , int capacity )
{
    int greatest = 0;
    int place = 0;
    int position = 0;
    int sorted[capacity];
    for( int i = 0 ; i < capacity; i++ )
    {
         greatest= ranking[i];
        
         for( int j = 0 ; j < capacity ; j++ )
         {
              if( greatest <= ranking[j] )
              {
                  greatest= ranking[j];
                  
                  place= j;
              }
              
         }
        
         sorted[position]= ranking[place];
         ranking[place]= 0;
         place= 0;
         position++;
    }
    
}
void bucked_sort(int array[] , int capacity , int biggest )
{
      
       int subarray1[capacity];
       int subarray2[capacity];
       int subarray3[capacity];
       int counter= 0,counter2= 0,counter3= 0;
      
       for( int i= 0 ; i < capacity ; i++ )
       {
          
            if( array[i] < biggest / 3 )
            {
               subarray1[counter]= array[i];
               ++counter;
            }else if( array[i] < biggest / 2 )
            {
             subarray2[counter2]= array[i];
               ++counter2;
            }else if( array[i] <= biggest )
            {
             subarray3[counter3]= array[i];
               ++counter3;
            }
       }
      
      
       sort(subarray1,counter);
       sort(subarray2,counter2);
       sort(subarray3,counter3);
}
int main(int argc,char * argv[])
{
  int capacity= atoi( * ( argv+1 ) );
  int numbers[capacity];
  int indices= 0;
  for( int i= 2 ; i < argc ; i++ )
  {
     numbers[indices]= atoi( * ( argv + i ) );
     indices++;
  }
  indices=0;
  int biggest= 0;
  for( int i= 0 ; i < capacity ; i++ )
  {
    if( numbers[i] > biggest )
    {
       biggest= numbers[i]; 
    }
  }
  bucked_sort( numbers , capacity , biggest );
  return(0);
}