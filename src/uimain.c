#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_CHAR 300


int main(){
  char word[MAX_CHAR];
  List *history = init_history();
  
  while(1){
    printf("1. Enter a word to tokenize, \n 2.Enter 'q' to quit the program, \n 3.Enter 'h' to check view history \n");
    printf("> ");
    fgets(word, MAX_CHAR, stdin);

    if (word[0] == 'q'){
      printf("Terminating program...");
      
      return 0;
    }
    else if(word[0] == 'h'){
      print_history(history);
    }else{
      char **tokens = tokenize(word);
      print_tokens(tokens);
      add_history(history, word);
    }
  }
  
  return 0;
}
