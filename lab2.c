#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isMember(char inputString[]) {
 int state = 0;
 int length = strlen(inputString);
 for (int i = 0; i < length; i++) {
 switch (state) {
 case 0:
 if (inputString[i] == '0')
 state = 1;
 else
 return false;
 break;
 case 1:
 if (inputString[i] == '1')
 state = 2;
 else
 return false;
 break;
 case 2:
 return true;
 }
 }
 return false;
}
int main() {
 char inputString[100];
 printf("Enter a string of 0s and 1s: ");
 scanf("%s", inputString);
 if (isMember(inputString)) {
 printf("Accepted\n");
 } else {
 printf("Rejected\n");
 }
 return 0;
}
