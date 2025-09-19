#include <stdio.h>
int main(){
  int c;
  while((c = getchar()) != EOF) {
    if(c == '\t'){
      printf("\\t");
      c = getchar();
    }
    if(c == '\b'){
      printf("\\b");
      c = getchar();
    }
    if(c == '\\'){
      printf("\\\\");
      c = getchar();
    }
    putchar(c);
  }
  return 0;
}
