#include <stdio.h>
#define MAX_CHAR 300


int main(){
  char word[MAX_CHAR];
  List *list = init_history();
  
  printf("Enter a word or Enter q to quit program: ");
  fgets(word, MAX_CHAR, stdin);

  if (word[0] == 'q'){
    printf("Terminating program...");
    return 0;
  }

  printf("You entered: %s\n", word);
  
  return 0;
}
