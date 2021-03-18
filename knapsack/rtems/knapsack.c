/*
 * 0-1 Knapsack Problem with Greedy Approach
 * File: knapsack.c
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

int  knapsack(int mass[],int valence[],int stuff_count,int full)
{
   int new_mass[stuff_count];
   int new_valence[stuff_count];
   int market[stuff_count];
   for(int y=0 ; y < stuff_count ; y++ )
   {   
       market[y]= valence[y] / mass[y];
      
   }  
 
   int place= 0;
   int most_valuable= 0;
   int taking= 0;
   int y= 0;
  
   for(int j= 0 ;j < stuff_count ; j++)
   {
      
       for(y= 0; y < stuff_count ; y++)
       {
          if( market[y] > most_valuable )
          {
               most_valuable= market[y];
               place= y;
          }
       }
      
       market[place]=0;
       
       new_mass[taking]= mass[place]; 
       new_valence[taking]= valence[place]; 
      
       taking++;
       
       most_valuable= 0;
       y= 0;
       place= 0;
   }
  
   int bag= 0;
  
   int full_taking= 0;
  
   for( y=0 ; y < stuff_count ; y++ )
   {
       
        if( new_mass[y] + bag >full )
        {
               return full_taking;
        }else{
             
               full_taking= full_taking + new_valence[y];
               bag = bag + new_mass[y];
               
        }
   }
   return full_taking;
}
rtems_task Init(rtems_task_argument arg)
{
   int capacity=0,stuff=0;
  
  capacity=100;
  stuff=4;
  int valence[stuff];
  int mass[stuff];
 
    valence[0]=20;
    valence[1]=30;
    valence[2]=50;
    valence[3]=5;
    mass[0]=50;
    mass[1]=20;
    mass[2]=100;
    mass[3]=70;
   int revenues=0;
 
   revenues= knapsack(mass,valence,stuff,capacity);
   
   
   exit(0);
}


