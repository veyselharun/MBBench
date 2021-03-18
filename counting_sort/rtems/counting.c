/*
 * Counting Sort Algorithm
 * File: counting.c
 * Author: Metin Kuzhan
 *         
 */
#include <bsp.h>

#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
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
  
  srand(time(NULL));
  
  int capacity=4;
  int numbers[capacity];
  numbers[0]=23;numbers[1]=2;numbers[2]=45;numbers[3]=33;

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
 
  for(int k=capacity - 1 ; k >= 0 ; k-- )
  { 
         location= numbers[k];
         new_location= B[location] - 1;
         C[new_location]= numbers[k]; 
  } 
 
   exit(0);
}


