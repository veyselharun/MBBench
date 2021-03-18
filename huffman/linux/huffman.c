/*
 * Fixed Huffman Encoding
 * File: huffman.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int strong(int base,int power)
{
    int strong_result= 1;
    for( int k= 0; k < power ; k++ )
    {
       
       strong_result=strong_result * base;
    }
   return strong_result;
}
int main(int argc,char * argv[])
{
  int character_count; 
 
  character_count=atoi(*(argv+1));
 
  char first;
  
  int different_character=0;
  char word[character_count];
  
  strcpy(word,*(argv+2));
 
  int frequency=0;
 
  int count=strlen(word);
 
  int frequencys[count];
  int alignment= 1;
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
  int collected=0;
 
  for( int l = 0 ; l < different_character ; l++ )
  {
     
      compress= compress + ( show_bit * frequencys[l] );
  }
  
  int precompress= count * 8;
  
  float economy= ( compress * 100 ) / precompress;
  
  return(0);
}
