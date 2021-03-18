/*
 * 0-1 Knapsack Problem with Greedy Approach
 * File: knapsack.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

float  knapsack(float mass[],float valence[],int stuff_count,int full)
{
   float new_mass[stuff_count];
   float new_valence[stuff_count];
   float market[stuff_count];
   for(int y=0 ; y < stuff_count ; y++ )
   {   
       market[y]= valence[y] / mass[y];
      
   }  
  
   int place= 0;
   float most_valuable= 0;
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
  
   bool is_full= false;
 
   float bag= 0;

   float full_taking= 0;
  
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
}
int main(int argc,char * argv[])
{
  int capacity=0,stuff=0;
  
  
  capacity=atoi(*(argv+1));
  stuff=atoi(*(argv+2));
  float valence[stuff];
  float mass[stuff];

  int indices=0;
  
  for( int i=3 ; i < argc - stuff ; i++ ) 
  {
     valence[indices]= atoi(*(argv+i));
     indices++;
  }
  indices=0;
 
  for( int i= stuff+3 ;i < argc ; i++ )
  {
     mass[indices]= atoi(*(argv+i));
     indices++;
  }
 
  float revenues=0;
  
  revenues= knapsack(mass,valence,stuff,capacity);
 
  return(0);
}