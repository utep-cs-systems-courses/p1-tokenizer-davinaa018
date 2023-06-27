#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize linked list to keep history  */
List *init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

/* Adding an item to history  */
void add_history(List *list, char *str){
  int itemId = 0;
  Item *newItem = list->root;

  while (newItem){
    newItem = newItem->next;
    itemId += 1;
  }
  newItem = malloc(sizeof(Item));
  newItem->id = itemId;
  newItem->str = str;
}


/* Print History  */
void print_history(List *list){
  Item *temp = list->root->next;
  /* Loops till its null/empty  */
  while (temp != 0){
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}
