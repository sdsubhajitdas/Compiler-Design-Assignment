#include <ctype.h>
#include <stdio.h>

void strip_extra_spaces(char* str) {
  int i, x;
  for(i=x=0; str[i]; ++i)
    if(!isspace(str[i]) || (i > 0 && !isspace(str[i-1])))
      str[x++] = str[i];
  str[x] = '\0';
}

int main(int argc, char* argv[]) {
  char str[] = "  If  you  gaze   into  the abyss,    the   abyss gazes also   into you.    ";
  strip_extra_spaces(str);
  printf("%s\n",str);
  return 0;
}