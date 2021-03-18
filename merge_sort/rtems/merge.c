/*
 * Merge Sort Algorithm
 * File: merge.c
 * Author: Metin Kuzhan
 *         
 */
#include <bsp.h>

#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_USE_DEVFS_AS_BASE_FILESYSTEM
#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_MAXIMUM_TASKS 1
#define CONFIGURE_INIT
#define RAND_MAX        0x7fffffff
#include <rtems/confdefs.h>
#include <rtems.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

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

rtems_task Init(rtems_task_argument arg)
{
   
  int N , g ;
  
  N= 4;
 
  int array[N];
  array[0]=20;
  array[1]=30;
  array[2]=25;
  array[3]=45;
 
  mergesort(array , 0 , N-1 );
  
  exit(0);
}


