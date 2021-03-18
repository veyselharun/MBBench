#include <bsp.h>
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
/*
 * Bucket Sort Algorithm
 * File: booth.c
 * Author: Metin Kuzhan
 *         
 */
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
	
  int number1=0,number2=0;  
  system("clear");
  number1=5;
  number2=9;
  int number1bit[4];
  int number1overflow;
  int number2bit[4];
  int divided;
  int segment= 0;
  divided= number1;
  
  for( int i= 3; i >= 0 ; i-- )
  {
    number1bit[i]= divided % 2;
    segment= divided / 2 ;
    divided= segment;
  }
  divided= 0;
  segment= 0;
  divided= number2;
  
  for( int i= 3 ; i >= 0 ; i-- )
  {
    number2bit[i]= divided % 2;
    segment= divided / 2;
    divided= segment;
  }
  
  int accumlator[4];
  for( int i= 0 ; i < 4 ; i++ )
  {
    accumlator[i]= 0;
    
  }
  int qnegative1= 0;
  int rotate[8];
 
  for( int i= 0 ; i < 4 ; i++ )
  {
    rotate[i]= accumlator[i];
    
  }
  int place= 4;
 
  for( int i= 0 ; i < 4 ; i++ )
  {
    rotate[place]= number2bit[i];
    place++;
  }
  int rotateswap[8];
  
  for( int i= 0 ; i < 8 ; i++ )
  {
    rotateswap[i]= rotate[i];  
  }
  
  
  for( int i= 0 ; i < 8 ; i++ )
  {
    if( i == 0 )
    {
      
    }
   
    if( i == 3 )
    {
      
    }
  }
  
  int step= 1;
  int number1bitcopy[4];
  for( int i = 0 ; i < 4 ; i++ )
  {
     if( rotate[7] == 1 )
     {
        if( qnegative1 == 0 )
        {
            
             for( int j= 0 ; j < 4 ; j++ )
             {
              number1bitcopy[j]= number1bit[j];
             }
             for( int j= 0 ; j < 4 ; j++ )
             {
               if( number1bitcopy[j] == 0 )
               {
                  number1bitcopy[j]= 1;
               }else if( number1bitcopy[j] == 1 )
               {
                  number1bitcopy[j]= 0;
               }
              }     
            
             number1bitcopy[3]= number1bitcopy[3] + 1 ;
             int getmod= 0;
             int modremaining= 0;
             if( number1bitcopy[3] > 1 )
             {
               getmod= number1bitcopy[3] % 2;
               modremaining= number1bitcopy[3] / 2;
               number1bitcopy[3]= getmod;
               number1bitcopy[2]= number1bitcopy[2] + modremaining;
             }   
             getmod= 0;
             modremaining= 0;
             if( number1bitcopy[2] > 1 )
             {
               getmod= number1bitcopy[2] % 2;
               modremaining= number1bitcopy[2] / 2;
               number1bitcopy[2]= getmod;
               number1bitcopy[1]= number1bitcopy[1] + modremaining;
             }  
             getmod= 0;
             modremaining= 0;   
             if( number1bitcopy[1] > 1 )
             {
               getmod= number1bitcopy[1] % 2;
               modremaining= number1bitcopy[1] / 2;
               number1bitcopy[1]= getmod;
               number1bitcopy[0]= number1bitcopy[0] + modremaining;
             }       
             getmod= 0;
             modremaining= 0;   
             if( number1bitcopy[0] > 1 )
             {
               getmod= number1bitcopy[0] % 2;
               modremaining= number1bitcopy[0] / 2;
               number1bitcopy[0]= getmod;
               number1overflow= modremaining;
            } 
           
            for( int i= 0 ; i < 4 ; i++ )
            {
              accumlator[i]= accumlator[i] + number1bitcopy[i];
    
            }
            
            for( int i= 0 ; i < 4 ; i++ )
            {
              rotate[i]= accumlator[i];
    
            }
            
            for( int i= 0 ; i < 8 ; i++ )
            {
               rotateswap[i]= rotate[i];
            }
           
            qnegative1= rotate[7];
            place= 0;
           
            for( int i= 1 ; i < 8 ; i++ )
            { 
               rotate[i]= rotateswap[place];
               place++;
            }
          
            rotate[0]= rotateswap[7];
            
         
            step++;
            
            for( int i= 0 ; i < 8 ; i++ )
            {
               if( i==0 )
               {
                
               }
              
               if( i==3 )
               {
                 
               }
            }
           
        }
        else if( qnegative1==1 )
        {
            
            for( int i= 0 ; i < 8 ; i++ )
            {
               rotateswap[i]= rotate[i];
            }
            
            qnegative1= rotate[7];
            place= 0;
           
            for( int i= 1 ; i < 8 ; i++ )
            {
               rotate[i]= rotateswap[place];
               place++;
            }
            
            rotate[0]= rotateswap[7];
           
           
            step++;
            
            for( int i= 0 ; i < 8 ; i++ )
            {
               if( i == 0 )
               {
                 
               }
              
               if(i==3)
               {
                 
               }
            }
            
        }
      }
      else if( rotate[7] == 0 )
      {
            if( qnegative1 == 1 )
            {
               
                
            for( int i= 0 ; i < 4 ; i++ )
            {
              accumlator[i]= rotate[i] + number1bit[i];
    
            }
          
            int getmod= 0;
            int modremaining= 0;   
            if( accumlator[3] > 1 )
            {
               getmod= accumlator[3] % 2;
               modremaining= accumlator[3] / 2;
               accumlator[3]= getmod;
               accumlator[2]= accumlator[2] + modremaining;
            }   
            getmod= 0;
            modremaining= 0;
            if( accumlator[2] > 1 )
            {
               getmod= accumlator[2] % 2;
               modremaining= accumlator[2] / 2;
               accumlator[2]= getmod;
               accumlator[1]= accumlator[1] + modremaining;
            }  
            getmod= 0;
            modremaining= 0;   
            if( accumlator[1] > 1 )
            {
               getmod= accumlator[1] % 2;
               modremaining= accumlator[1] / 2;
               accumlator[1]= getmod;
               accumlator[0]= accumlator[0] + modremaining;
            }       
            getmod= 0;
            modremaining= 0;   
            if( accumlator[0] > 1 )
            {
               getmod= accumlator[0] % 2;
               modremaining= accumlator[0] / 2;
               accumlator[0]= getmod;
               number1overflow= modremaining;
            } 
            
            for( int i= 0 ; i < 4 ; i++ )
            {
              rotate[i]= accumlator[i];
    
            } 
           
            for( int i= 0 ; i < 8 ; i++ )
            {
               rotateswap[i]= rotate[i];
            }
            qnegative1= rotate[7];
            place= 0;
           
            for( int i= 1; i < 8 ; i++ )
            {
               rotate[i]= rotateswap[place];
               place++;
            }
            
            rotate[0]= rotateswap[7];
           
           
            step++;
            
            for( int  i= 0 ; i < 8 ; i++ )
            {
               if( i==0 )
               {
                
               }
              
               if(i==3)
               {
                
               }
            }
            
            }
            else if( qnegative1 == 0 )
            {
                
                for( int i= 0 ; i < 8 ; i++ )
                {
                  rotateswap[i]= rotate[i];
                }
               
                qnegative1= rotate[7];
                place= 0;
             
                for(int i= 1 ; i < 8 ; i++ )
                {
                  rotate[i]= rotateswap[place];
                  place++;
                }
                
                rotate[0]= rotateswap[7];
               
               
                step++;
                
                for( int i= 0 ; i < 8 ; i++ )
                {
                  if(i==0)
                  {
                     
                  }
                 
                  if(i==3)
                  {
                     
                 }
            }
            
            }
        }
    
    
     
  }
  
 
  int product=0;
  for( int l= 0 ; l < 8 ; l++ )
  {
         if( rotate[l] == 1 )
         {
            product= product + strong(2,l);
         }
  }
  exit(0);
}


