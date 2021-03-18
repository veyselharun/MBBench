/*
 *  MBench Benchmark Suite
 * 
 *  Quick Sort Program for linux
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NOTHREADS 2

int N;
int *a;

int  Partition(int p,int r)
{
   int array[N]; 
    
     for (int i = 0; i < N; i++)
                               array[i]=*(a+i);
    int x=array[r];;
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

              
                
                
                ret = pthread_create(&tid1, NULL, quickSort, &n1);//Recurrent study is performed
                if (ret) {
                        printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, ret);    
                        exit(1);
                }

             
                ret = pthread_create(&tid2, NULL, quickSort, &n2);//Recurrent study is performed
                if (ret) {
                        printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, ret);    
                        exit(1);
                }
                
                pthread_join(tid1, NULL);
				
                pthread_join(tid2, NULL);

             }
                pthread_exit(NULL);
}


int main(int argc, char **argv) {
    int  g;
   
    N= atoi( * ( argv + 1 ) ); 
   
    int array[N];
   
    int indices= 0;
   
    for( g= 2 ; g < argc ; g++ )
    {
       
       array[indices]= atoi(*(argv+g));
       
       ++indices;
    }
    
   
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
               
                for (i = 0; i < N; i++)
                              

               
                return 0;
}