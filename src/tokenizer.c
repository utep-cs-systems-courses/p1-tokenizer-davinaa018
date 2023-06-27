#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Returns true if char is either a tab ('\t') or " "*/
int space_char(char c){
  if (c == '\t' || c == ' '){
    return 1
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

char *token_start(char *str){
  int i;
  for (i = 0; *(str + i) != '\0'; i++){
    /* Checks that current position is not an empty space */
    if (non_space_char(*(str+i))){
      return str+i;
    }
  }
  return str+i;
}

char *token_terminator(char *token){
  int i;
  for (i = 0; (token + i) != '\0'; i++){
    /* Checks that current position is an empty space  */
    if (space_char(*(token + i))){
      return token + i;
    }
  }
  return token + i;
}

int count_tokens(char *str){
  int tokenCount = 0;
  char *token = token_start(str);
  while(*token != '\0'){
    /*Checks that current value is a valid token */
    if(non_space_char(*token)){
      tokenCount += 1;
    }
    /* Goes to the end of the token/string/word */
    token = token_terminator(token);
    /* Goes to the beginning of the token/word */
    token = token_start(token);
  }
  return 0;
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

void free_tokens(char **tokens){
  for (int i = 0; tokens[i] != 0; i++){
    /*
      Free ups the space use by functions like malloc/calloc
      Free ups single words
     */
    free(tokens[i]);
  }
  /* Free ups whole token  */
  free(tokens);
}
