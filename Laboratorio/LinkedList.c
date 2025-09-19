#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
Node* BuildOneTwoThree(){
  Node* head = malloc(sizeof(Node));
  head->data = 1;
  head->next = malloc(sizeof(Node));
  head->next->data = 2;
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 3;
  head->next->next->next = NULL;

  return head;
}
void LinkTest(){
  Node* head = BuildOneTwoThree();
  Node* newNode = malloc(sizeof(Node));
  newNode->data = 1;
  newNode->next = head;
  head = newNode;
}
int Length(Node* head){
  int count = 0;
  while (head) {
    count++;
    head = head->next;
  }
  return count;
} 
