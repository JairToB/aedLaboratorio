#include "LinkedList.h"
#include <stdio.h>
int main(){
  struct Node* myList = BuildOneTwoThree();

  wrongPush(myList, 4);

  int count = Count(myList, 2);
  printf("%d\n", count);
  int lastNode = GetNth(myList, 2);
  printf("%d\n", lastNode);
  DeleteList(&myList);
  int countAgain = Count(myList, 2);
  printf("%d", countAgain);
  return 0;
}
