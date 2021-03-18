/*
 * Cesar Algorithm
 * File: cesar.c
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
  int c=0;
  char text[]="rtems";
  int sample_count=strlen(text);
  int position=1;
  int length=2;
  char sub[sample_count];
  while (c < length) {
      sub[c] = text[position+c-1];
      c++;
   }
  
  int word_count= strlen(sub);
 
  int shifting_count= 1+rand()%sample_count;
 
  char plain_text[word_count];
 
  strcpy(plain_text,sub);

  for(int i=0 ; i < word_count ; i++ )
  {
    
     int place= (int) plain_text[i];
     
     int new_letter= ( ( ( place - 97 )+ shifting_count ) % 25 )+ 97;
    
  }
  
  exit(0);
}


