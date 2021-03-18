/*
 * Standart Deviation
 * File: standart_deviation.c
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
double square_root( double number)
{
  int i;
  double x;
  x=1;

  for( i=0 ; i < 1000 ; i++ )
  {
    x=0.5 * ( x + ( number / x ) );
  }

  return x;

}
rtems_task Init(rtems_task_argument arg)
{
	
	
  int   n, top;
  float average;

  
   top = 0;      
   n   = 5;      
   int numbers[n];
   numbers[0]=4;
   numbers[1]=2;
   numbers[2]=10;
   numbers[3]=5;
   numbers[4]=20;
   int i=0;
   while(i<5)                   
   {    

      top += numbers[i];                        
      i++;
   }

   average = (float) top/n;                 
   int deviation =0,temp= 0;
   int square=0; 
  
   for( int i = 0; i <= n; i++ )
   {
         temp= average - numbers[n];
         square=  temp * temp;
         deviation= deviation+square;
   }
   double deflection=0;
  
   deflection= square_root(deviation);
  
   exit(0);
}


