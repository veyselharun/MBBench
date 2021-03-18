/*
 * Merge Sort Algorithm
 * File: merge.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>

void  merge(int array[],int first,int medium,int last)
{
   int i,j,k;
   
   int array_left= medium - first + 1;
   
   int array_right= last - medium;
   
   int left[array_left];
  
   int right[array_right];
   
   for( i= 0 ; i < array_left ; i++ )
   {
       left[i]= array[first + i ];
   }
   
   for( j= 0 ; j < array_right ; j++ )
   {
       right[j]= array[medium + 1 + j ];
   }
  aaaa
   i= 0,j= 0,k= first;
   
   while( i < array_left && j < array_right )
   {
      
       if(left[i] <= right[j])
       {
           array[k]= left[i];
           i++;
       }else 
       {
          array[k]= right[j];
          j++;  
           
       }
    
      k=k+1;
   }
  
   while( i < array_left )
   {
        array[k]= left[i]; i++; k++;
   }
   
   while( j < array_right )
   {
        array[k]= right[j]; j++; k++;
   }
}

void  mergesort(int array[],int left,int right)
{ 
  
   if( left < right )
   {
       
       int middle = left + (right-left) / 2;
       
       mergesort(array,left,middle);
       mergesort(array,middle+1,right);
     
       merge(array,left,middle,right);
   }
}
int main(int argc,char * argv[])
{
  
  int N , g , v ;
  
 
  N= atoi( * ( argv + 1 ) );
 
  int array[N];

  int indices= 0;
  
  for( g= 2 ; g < argc ; g++ )
  {
      
       array[indices]= atoi(*(argv+g));
       
       ++indices;
  }
  
  mergesort(array , 0 , N-1 );
  return(0);
}