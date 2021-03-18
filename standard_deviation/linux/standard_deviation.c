/*
 * Standart Deviation
 * File: standart_deviation.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
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
int main(int argc,char * argv[])
{ 
  
  
  FILE *dg;        
  int   number,n, top;
  float average;

   if( (dg=fopen("sample.txt","r")) == NULL )
     exit(1);

  
   top = 0;      
   n   = 0;     

   while( !feof(dg) )                    
   {
      fscanf( dg,"%d",&number ); 


      if( number ) n++;   
                         

      top += number;                       
   }

   fclose(dg);                         

   average = (float) top/n;                 
  
   if( (dg=fopen("sample.txt","r")) == NULL )
    exit(1);
   float array[n];
   int deviation =0,temp= 0;
   n=0;
   while( !feof(dg) )                    
   {
      fscanf(dg,"%d", &number);


      if( number ) n++;  
                         

      array[n]= number;                   
   }
   
   fclose(dg);     
   int square=0; 
    
   for( int i = 0; i <= n; i++ )
   {
         temp= average - array[n];
         square=  temp * temp;
         deviation= deviation+square;
   }
   double deflection=0;
  
   deflection= square_root(deviation);
   
   return(0);
}