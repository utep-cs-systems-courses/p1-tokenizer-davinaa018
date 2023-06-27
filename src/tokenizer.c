#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Returns true if char is either a tab ('\t') or " "*/
int space_char(char c){
  if (c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

/* Return true if char is not a tab ('\t') or a ' '  */
int non_space_char(char c){
  if (c != '\t' || c != ' '){
    return 1;
  }
  return 0;
}

char *word_start(char *str){
  int i;
  for (i = 0; *(str + i) !+ '\0'; i++){
    /* Checks that current position is not an empty spaceOB */
    if (non_space_char(*(str+i))){
      return str+i;
    }
  }
  return str+i;
}


char *copy_str(char *inStr, short len){
  char *strCopy = malloc((len+1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++){
    strCopy[i] = inStr[i];
  }
  /* Making the last value null */
  strCopy[i] = '\0';
  
  return strCopy;
}

/* Prints all tokens  */
void print_tokens(char **tokens){
  for (int i = 0; tokens[i] != 0; i++){
    printf("%s\n", tokens[i]);
  }
}
