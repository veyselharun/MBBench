/*
 * Greatest Common Divisor for Two Numbers
 * File: gcd.c
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
		
		int number1 = 0;
		int number2 = 0;  
	  
	  number1=24;
	  number2=3;
         
	  int dividing=0,gcd=1;
	  if(number1<=number2)
	  {
		 dividing=number1;
	  }else
	  {
		 dividing=number2;
	  }
	  
	  for(int i=2 ;i <= dividing; i++)
	  {
		
		  if( number1 % i == 0 && number2 % i ==0 )
		  {
			 
			 gcd=i;    
		  }
	  }
	 
	  if(gcd==1)
	  {
		
	  }else
	  {
		 
	  }
	  
	  exit(0);
}


