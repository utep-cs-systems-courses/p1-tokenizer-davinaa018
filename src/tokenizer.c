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
    /* Goes to the end of the token/string/word */
    token = token_terminator(token);
    /* Goes to the beginning of the token/word */
    token = token_start(token);
    tokenCount += 1;
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
  printf("start of tokenize");
  int num_token = count_tokens(str);
  char **tokens =(char**)  malloc((num_token + 1) * sizeof(char*));
  if(tokens == (char**) NULL) exit(-1);
  
  char *tokenStart = str;
  char *tokenEnd;
  for (int i = 0; i < num_token; i++){
    printf("Start");
    tokenStart = token_start(tokenStart);
    tokenEnd = token_terminator(tokenStart);
    tokens[i] = copy_str(tokenStart, tokenEnd - tokenStart);
    tokenStart = tokenEnd;
  }
  tokens[num_token] = '\0';
  tokens[num_token] = (char*) NULL;
  return tokens;
}

/* Prints all tokens FIX  */
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

      FIX
     */
    free(tokens[i]);
  }
  /* Free ups whole token  */
  free(tokens);
}
