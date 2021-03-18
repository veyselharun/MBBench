/*
 * RSA Key Production
 * File: rsa.c
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

float myremaning(float a ,float b)
{
   int quot=(int)a/b;
   return a-(quot*b);
   
}

float strong(float base,float power)
{
    float strong_result= 1;
    for( float k= 0; k < power ; k++ )
    {

       strong_result=strong_result * base;
    }
   return strong_result;
}

bool bool_prime(float number)
{
    bool prime= true;
    for( float  i = 2 ; i < number ; i++ )
    {
       if( myremaning( number , i ) == 0 )
         prime= false;
    }
  return prime;
 
}

bool bool_interprime(float number1,float number2)
{
    bool prime= true;
    
    for( float  i = 2 ; i < number2 ; i++ )
    {
       if( myremaning(number1 , i ) == 0 && myremaning( number2 , i ) ==0 )
         prime= false;
    }
  return prime;
 
}

bool bool_intermodone(float number1,float number2,float number3)
{ 
       bool one= false;
       float multi= number1 * number2;
       float remaining= myremaning(multi,number3);
       if( remaining == 1 )
       {
         one= true;
       }
  
  return one;
 
}
rtems_task Init(rtems_task_argument arg)
{
         
  float prime_number1= 0,prime_number2= 0;
  int range=100;
  bool prime=false,prime2=false;
  while( prime == false || prime2 == false )
  {
     srand(time(NULL));
     int a=rand()%range;
     int b=rand()%range;

     prime_number1= myremaning(a,range);
     prime_number2= myremaning(b,range);
     prime= bool_prime(prime_number1);
     prime2= bool_prime(prime_number2);

     if( prime == true )
     { 
       if( prime_number1 < 3 )
        prime= false;
     }
     if( prime2 == true )
     { 
       if( prime_number2 < 3 )
        prime2= false;
     }
  }
  float n=prime_number1 * prime_number2;
  float teta=(prime_number1 - 1 )*(prime_number2 -1);
  int temp=(prime_number1 -1)*(prime_number2 -1);
  float e=0;
  bool interprime=false;
  while( interprime==false )
  {
     srand(time(NULL));
     e=rand()%temp;

     interprime= bool_interprime(e,temp);

     if( e <= 1 )
     {
       interprime= false;
     }
  }
  bool modone=false;
  float d=0;
  while( modone == false )
  {

     srand(time(NULL));
     d=rand()%temp;
     modone= bool_intermodone(e,d,temp);
     if(d<=1)
     {
       modone=false;
     }
    
  } 

  float c= 0;
  float m= 3;
  float new_e=e;
  float result= strong(m,new_e);
  float new_n=n;
  c= myremaning(result,new_n);
 
  float decrypted_message=0;
  float new_d=d;
  float result2=strong(c,new_d);
  decrypted_message=myremaning(result2,new_n);
 
  exit(0);
}


