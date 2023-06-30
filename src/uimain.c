#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_CHAR 300


int main(){
  char word[MAX_CHAR];
  List *history = init_history();
  
  while(1){
    printf("1. Enter a word to tokenize, \n 2.Enter 'q' to quit the program, \n 3. Enter '!' followed by a number to get that history \n 4.Enter 'h' to check view history \n");
    printf("> ");
    fgets(word, MAX_CHAR, stdin);

    /* Option to terminate program */
    if (word[0] == 'q'){
      printf("Terminating program...");
      free_history(history);
      return 0;
    }
    /* Option to retrieve full history */
    else if(word[0] == 'h'){
      print_history(history);
      
      /* Option to retrieve a certain history */
    }else if(word[0] == '!'){
      /* Atoi converts str to int */
      char *newHistory = get_history(history, atoi(word+1));
      if (newHistory == NULL){
	printf("No history found \n");
      }else{
	char **tokens = tokenize(newHistory);
	print_tokens(tokens);
	free_tokens(tokens);
      }

      /* Option to input a word */
    } else{
      char **tokens = tokenize(word);
      print_tokens(tokens);
      add_history(history, word);
    }
  }
  
  return 0;
}
