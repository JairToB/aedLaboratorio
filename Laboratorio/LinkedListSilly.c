#include "LinkedList.h"
#include <stdlib.h>
// assert()?
Node* BuildOneTwoThree() {
  Node* variante[3];
  for (int i = 0; i < 3; ++i) {
    variante[i] = malloc(sizeof(Node));
  }
  for (int i = 0; i < 3; ++i) {
    variante[i]->data = i + 1;
    variante[i]->next = variante[i + 1];
    if ((i + 1) == 3) {
      variante[i]->next = NULL;
    }
  }
  return variante[0];
}
