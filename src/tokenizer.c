#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Returns true if char is either a tab ('\t') or " "*/
int space_char(char c){
  return (c == ' ' || c == '\t');
}

/* Return true if char is not a tab ('\t') or a ' '  */
int non_space_char(char c){
  return (c != ' ' && c != '\t' && c != '\0');
}

char *token_start(char *str){
  while(*str != '\0'){
    if(non_space_char(*str)){
      return str;
    }
    str++;
  }
  return 0;
}

char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

int count_tokens(char *str){
  int tokenCount = 0;
  char *token = str;
  while(*token != '\0'){
    token = token_start(token);
    token = token_terminator(token);
    tokenCount++;
  }
  return tokenCount;
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

char **tokenize(char *str){
  int num_tokens = count_tokens(str);
  char **tokens = malloc((num_tokens + 1) * sizeof(char*));
  int i = 0;
  while(*str != '\0'){
    str = token_start(str);
    char *end = token_terminator(str);
    tokens[i] = copy_str(str, end-str);
    str = end;
    i++;
  }
  /* Makes last index null/zero */
  tokens[i] = 0;
  return tokens;
}

/* Prints all tokens  */
void print_tokens(char **tokens){
  while(*tokens != 0){
    printf("%s",*tokens);
    tokens++;
  }
}

void free_tokens(char **tokens){
  char** temp = tokens;
  while(*temp != 0){
    free(*temp);
    temp++;
  }
  free(tokens);
}
