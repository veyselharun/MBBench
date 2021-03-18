/*
 * Fixed Huffman Encoding
 * File: huffman.c
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
int strong(int base,int power)
{
    int strong_result= 1;
    for( int k= 0; k < power ; k++ )
    {
      
       strong_result=strong_result * base;
    }
   return strong_result;
}
rtems_task Init(rtems_task_argument arg)
{
   int c=0;
  char text[]="rtemsprogramming";
  int sample_count=strlen(text);
  int position=rand()%sample_count;
  srand(time(NULL));
  int length=1+rand()%sample_count;
  char sub[sample_count];
  while (c < length) {
      sub[c] = text[position+c-1];
      c++;
   }
  int character_count; 
 
  character_count=strlen(sub);
 
  char first;

  int different_character=0;
  char word[character_count];
  
  strcpy(word,sub);
  
  int frequency=0;
 
  int count=strlen(word);
  
  int frequencys[count];
  int place= 0;
 
  for( int i= 0; i < count ; i++ )
  {
     first = word[i];
    
     for( int j= 0 ; j < count ; j++ )
     {
        if( first == word[j] )
        {
          frequency++; 
        }   
     }
    
     if( first == '\0' )
     {
       
     }else
     {
     
       frequencys[place-1]=frequency;
       place++;
       different_character++;
       
     } 
    
     for( int j= 0; j < count ; j++)
     {
        if( first == word[j] )
        {
          word[j]= '\0'; 
        }           
     }
    
     first= '\0';
    
     frequency= 0;
     
  }
  int bit=1;
  int show_bit=0;
  int scope=0;
 
  while( true )
  {
     scope= strong( 2 , bit );
     if(scope >= different_character )
     {
      
         show_bit=bit;
         break;
     }else
     {
        bit++;
     
     }
  }
  
  int compress=0;
  
  for( int l = 0 ; l < different_character ; l++ )
  {
     
      compress= compress + ( show_bit * frequencys[l] );
  }
  
  int precompress= count * 8;
 
  float economy= ( compress * 100 ) / precompress;
 
  exit(0);
}


