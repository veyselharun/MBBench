/*
 * Cesar Algorithm
 * File: cesar.c
 * Author: Metin Kuzhan
 *         
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char * argv[])
{ 
  
  char encrypted_text= 0;
  int word_count= strlen(*(argv+1));
  
  int shifting_count= atoi(*(argv+2));
  
  char plain_text[word_count];
  
  strcpy(plain_text,*(argv+1));
 
  for(int i=0 ; i < word_count ; i++ )
  {
     int place= (int) plain_text[i];
     
     int new_letter= ( ( ( place - 97 )+ shifting_count ) % 25 )+ 97;
  }
  return(0);
}