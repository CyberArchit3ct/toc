#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
// Function to check if a string is a valid C identifier
bool isValidIdentifier(const char* identifier) {
 if (identifier == NULL || !isalpha(identifier[0]) && identifier[0] != '_')
 return false;
 for (int i = 1; i < strlen(identifier); i++) {
 if (!isalnum(identifier[i]) && identifier[i] != '_')
 return false;
 }
 return true;
}
// Function to check if a string is a C keyword
bool isKeyword(const char* keyword) {
 const char* keywords[] = {
 "auto", "break", "case", "char", "const", "continue", "default", "do",
 "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
 "long", "register", "return", "short", "signed", "sizeof", "static",
 "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
 };
 int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
 for (int i = 0; i < numKeywords; i++) {
 if (strcmp(keyword, keywords[i]) == 0)
 return true;
 }
 return false;
}
int main() {
 char input[100];
 printf("Enter an identifier or keyword: ");
 scanf("%s", input);
 if (isValidIdentifier(input)) {
 if (isKeyword(input)) {
 printf("%s is a valid identifier and a C keyword.\n", input);
 } else {
 printf("%s is a valid identifier.\n", input);
 }
 } else {
 printf("%s is not a valid identifier.\n", input);
 }
 return 0;
}
