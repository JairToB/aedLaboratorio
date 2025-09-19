#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);
int main(){
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  max = 0;
  while((len = getLine(line, MAXLINE)) > 0){
    if(len > max){
      max = len;
      copy(longest, line);
    }
  }
  if(max > 0){
    printf("%s", longest);
  }
  reverse(longest);
  
  return 0;
}
int getLine(char s[], int lim){
  int c,i = 0;
  while(i < lim-1 && (c = getchar()) != EOF && c != '\n'){
    *s = c;
    ++s;
    ++i;
  }
  if(c == '\n'){
    *s = c;
    ++s;
    ++i;
  }
  *s = '\0';
  return i;
}
void copy(char to[], char from[]){
  int i;
  i = 0;
  while((to[i] = from[i]) != '\0'){
    ++i;
  }
}
void reverse(char s[]){
  int i = 0;
  char newS[MAXLINE];
  while(*s != '\0'){
    ++s; 
    ++i;
  }
  int j = 0;
  char c;
  while(i >= 0){
    newS[j] = *s;  
    --s;
    printf("%c", newS[j]);
    --i;
    ++j;
  }
  newS[j] = '\0';
}
