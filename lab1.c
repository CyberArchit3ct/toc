#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  int len, i, j;

  printf("Enter a string: ");
  fgets(str, 100, stdin);
  
  // Remove trailing newline (if present)
  len = strlen(str);
  if (str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }

  printf("\nPrefixes:\n");
  for (i = 0; i < len; i++) {
    for (j = 0; j <= i-1; j++) {
      printf("%c", str[j]);
    }
    printf("\n");
  }

  printf("\nSuffixes:\n");
  for (i = 0; i < len; i++) {
    for (j = i; j < len; j++) {
      printf("%c", str[j]);
    }
    printf("\n");
  }

  printf("Substrings:\n");
  for (i = 0; i < len; i++) {
    for (j = i + 1; j <= len; j++) {
      for (int k = i; k < j; k++) {
        printf("%c", str[k]);
      }
      printf("\n");
    }
  }

  return 0;
}
