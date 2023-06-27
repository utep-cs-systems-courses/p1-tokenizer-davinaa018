#include <stdio.h>
#define MAX_CHAR 300


int main(){
  char word[MAX_CHAR];

  printf("Enter a word: ");
  fgets(word, MAX_CHAR, stdin);

  printf("You entered: %s\n", word);
  
  return 0;
}
