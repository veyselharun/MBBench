/*
 *  MBench Benchmark Suite
 * 
 *  Quick Sort Program for RTEMS
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */

#include <sched.h>
#include <bsp.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#define NOTHREADS 5
int N;
int *a;
int  Partition(int p,int r)
{
 
   int array[N]; 
     for (int i = 0; i < N; i++)
                               array[i]=*(a+i);
    int x=array[r];
    int temp,temp2;
    int i=p-1;

    for(int j = p; j <= r-1 ;j++) 
    {
        if(array[j] <= x)
        {
          i=i+1;
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;  
        }
    }
    temp2=array[i+1];
    array[i+1]=array[r];
    array[r]=temp2; 
	
    for (int i = 0; i < N; i++)
                              *(a+i)= array[i];
    return i+1;
   
} 


typedef struct node {
int i;
int j;
} NODE;


void * quickSort(void *a)
{
                NODE *p = (NODE *)a;
                NODE n1, n2;
           
           if(p->i<p->j)
           {
                int q = Partition(p->i,p->j);
                pthread_t tid1, tid2;
                int ret;

                n1.i = p->i;
                n1.j = q-1;

                n2.i = q+1;
                n2.j = p->j;

              
                
                
                ret = pthread_create(&tid1, NULL, quickSort, &n1);
              

               
                ret = pthread_create(&tid2, NULL, quickSort, &n2);
               
                
                pthread_join(tid1, NULL);
			   
                pthread_join(tid2, NULL);

             }
                pthread_exit(NULL);
}



void *POSIX_Init()
{
    
          
    N=10; 
    
    int array[N];
    array[0]=90;
    array[1]=30;
    array[2]=6;
    array[3]=40;
    array[4]=10;
    array[5]=20;
    array[6]=15;
    array[7]=5;
    array[8]=35;
    array[9]=7;
    
    a=calloc(N, sizeof(int) );
        for (int i = 0; i < N; i++)
                               *(a+i)=array[i];
        
                 int i;
                NODE m;
                m.i = 0;
                m.j = N-1;
                pthread_t tid;

                int ret; 
              
                ret=pthread_create(&tid, NULL, quickSort, &m);
                if (ret) {
                          
                        exit(1);
                }
               
                pthread_join(tid, NULL);
  
	  exit(0); 

}

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_MAXIMUM_POSIX_THREADS              10
#define CONFIGURE_POSIX_INIT_THREAD_TABLE
#define CONFIGURE_INIT
#include <rtems/confdefs.h>

