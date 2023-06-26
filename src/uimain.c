#include <stdio.h>
#define MAX_CHAR 300


int main(){
  char word[MAX_CHAR];

  printf("Enter a word: ");
  scanf("%s", word);

  printf("You entered: %s\n", word);
  
  return 0;
}
