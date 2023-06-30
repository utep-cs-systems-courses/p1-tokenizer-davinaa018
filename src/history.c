#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize linked list to keep history  */
List *init_history(){
  List *list = (List*) malloc(sizeof(List));
  return list;
}

/* Adding an item to history  */
void add_history(List *list, char *str){
  Item *newItem = (Item*) malloc(sizeof(Item));
  char *newPointer = str;
  if(newPointer == NULL) exit(-1);

  while(*newPointer != '\0'){
    newPointer++;
  }

  newItem -> str = copy_str(str, newPointer - str);
  Item *currentItem = list -> root;
  int id = 2;
  if(currentItem == NULL){
    list -> root = newItem;
    newItem -> id = 1;
  }else{
    while(currentItem -> next != NULL){
      currentItem = currentItem -> next;
      id++;
    }
    newItem -> id = id;
    currentItem -> next = newItem;
  }
}


/* Print History  */
void print_history(List *list){
  Item *temp = list->root;
  /* Loops till its null/empty  */
  while (temp != NULL){
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}
