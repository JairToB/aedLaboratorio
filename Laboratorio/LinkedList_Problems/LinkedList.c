#include "LinkedList.h"
#include <stdlib.h>
#include <assert.h>
struct Node* BuildOneTwoThree(){
  struct Node* head = malloc(sizeof(struct Node));
  head->data = 1;
  head->next = malloc(sizeof(struct Node));
  head->next->data = 2;
  head->next->next = malloc(sizeof(struct Node));
  head->next->next->data = 3;
  head->next->next->next = NULL;

  return head;
}

int Count(struct Node* head, int number){
  int c = 0;
  while(head){
    if(head->data == number){
      c++;
    }
    head = head->next;
  }
  return c;
}

int GetNth(struct Node* head, int index){
  int i = 0;
  while(i != index){
    i++;
    head = head->next;
    assert(head != NULL);
  }
  return head->data;
}

void DeleteList(struct Node** headRef){
  struct Node* temporal = *headRef;
  while(*headRef){
    *headRef = (*headRef)->next;
    free(temporal);
    temporal = *headRef;
  }
  *headRef = NULL;
}

void wrongPush(struct Node* head, int data){
  struct Node* newNode = malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->next = head;

  head = newNode;
}

void Push(struct Node** headReaf, int data){
  struct Node* newNode = malloc(sizeof(struct Node));
  
}

void changeToNull(struct Node** pointer);
