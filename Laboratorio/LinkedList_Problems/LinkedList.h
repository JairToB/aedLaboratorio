#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct Node{
  int data;
  struct Node* next;
};
struct Node* BuildOneTwoThree();
int Count(struct Node*, int);
int GetNth(struct Node*, int);
void DeleteList(struct Node**);
void wrongPush(struct Node*, int);
void Push(struct Node**, int);
void changeToNull(struct Node**);
#endif
