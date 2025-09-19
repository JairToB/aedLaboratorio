#include <stdio.h>
int main(){
  int c;
  int BlankCounter = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++BlankCounter;
    }
    if (BlankCounter > 1) {
      while ((c = getchar()) == ' ');
      BlankCounter = 0;
    }
    putchar(c);
  }
  return 0;
}
