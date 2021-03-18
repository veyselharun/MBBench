/*
 * Miller Rabin Algorithm
 * File: miller.c
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

int strong(int base,int power)
{
    int strong_result= 1;
    for( int k= 0; k < power ; k++ )
    {
      
       strong_result=strong_result * base;
    }
   return strong_result;
}
int miller( int m ,int n)
{
  int a=0;
  while(true)
  {
    
     srand(time(NULL));
     a=0;
     while(a==0)
      a= rand()%(n-1);
     int power2= strong(a,m);
     int divide= power2%n;
     int new_divide=strong(divide,2)%n;
     if(new_divide == 1 )
     {
       break;
     }
    }
  return a;
}
rtems_task Init(rtems_task_argument arg)
{
  
  int n=20;
  int prime= n-1;
  int divide= 0;
 
  for( int i= 0 ; i < prime ; i++ )
  {
     if( prime % 2 == 0)
     {
          prime= prime / 2;
          divide++;
     }

  }
 
  int power= strong( 2, divide);
 
  int m=(n-1)/power;
  int prime_result= miller(m,n);
  
  exit(0);
}


