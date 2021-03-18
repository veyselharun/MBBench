/*
 * Radix Sort Algorithm
 * File: radix.c
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

rtems_task Init(rtems_task_argument arg)
{
            
  int number_count=5;

  int * numbers,*numbers_copy;

  numbers= malloc(sizeof(int)*number_count);
  numbers_copy= malloc(sizeof(int)*number_count);

     numbers[0]=20;
     numbers[1]=5;
     numbers[2]=45;
     numbers[3]=34;
     numbers[4]=53;

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

   int indices=0;

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
	  
   exit(0);
}


