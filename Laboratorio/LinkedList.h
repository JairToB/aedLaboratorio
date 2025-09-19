#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct Node{
  int data;
  struct Node* next;
}Node;
Node* BuildOneTwoThree();
int Length(Node* head);
void LengthTest();

#endif
