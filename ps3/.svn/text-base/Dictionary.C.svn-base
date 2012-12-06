#include <stdio.h>  // C   (.h),    printf, scanf, FILE, etc 
#include <sstream>  // C++ (no h)    
#include <stdlib.h> // C   (.h),    exit, other nice functions  
#include <iostream>

#include "Dictionary.h"

bool Dictionary::spelled_correctly(string word)
{
  return(hashTable->contains(word));
}

void Dictionary::read_file(string file_name)
{
  printf("Reading file...");
  FILE *file; 
 
  file = fopen(file_name.c_str(),"r");
 
  if ( !file ) { 
      printf("Error opening dictionary file!\n"); 
      exit(-1);  // or return -1 
  }  

  char line[1000];
  string lineString = "";
  int count = 0;
  while ( fgets(line,1000,file)) 
    {
      lineString = string(line);
      lineString = lineString.substr(0,lineString.length() - 1); // Remove the \n at the end

      hashTable->add(lineString);
      //bst->add(lineString, bst->getRoot());
      
      if(count % 500 == 0)
	printf(".");

      count++;
    } 
 
  printf("file read!\n");
}
