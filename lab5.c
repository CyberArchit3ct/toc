#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
int turingMachine(char inputString[]) {
 char tape[MAX_LENGTH];
 strcpy(tape, inputString);
 strcat(tape, "_"); // Add a blank symbol at the end of the tape
 char state[] = "q0";
 int head = 0;
 while (1) {
 char symbol = tape[head];
 if (strcmp(state, "q0") == 0) {
 if (symbol == '0') {
 strcpy(state, "q1");
 head++;
 } else if (symbol == '_') {
 return 0; // Reject if the tape ends without reaching the blank symbol
 } else {
 return 0; // Reject if the first symbol is not 0
 }
 } else if (strcmp(state, "q1") == 0) {
 if (symbol == '0') {
 strcpy(state, "q1");
 head++;
 } else if (symbol == '1') {
 strcpy(state, "q2");
 head++;
 } else {
 return 0; // Reject if the symbol is neither 0 nor 1
 }
 } else if (strcmp(state, "q2") == 0) {
 if (symbol == '1') {
 strcpy(state, "q2");
 head++;
 } else if (symbol == '_') {
 strcpy(state, "q3");
 head--;
 } else {
 return 0; // Reject if the symbol is neither 1 nor blank
 }
 } else if (strcmp(state, "q3") == 0) {
 if (symbol == '1') {
 strcpy(state, "q3");
 head--;
 } else if (symbol == '0') {
 strcpy(state, "q4");
 head--;
 } else {
 return 0; // Reject if the symbol is neither 0 nor 1
 }
 } else if (strcmp(state, "q4") == 0) {
 if (symbol == '_') {
 strcpy(state, "q0");
 head++;
 } else {
 return 0; // Reject if the symbol is not blank
 }
 }
 if (strcmp(state, "q0") == 0 && head == strlen(tape)) {
 return 1; // Accept if the tape ends at state q0
 }
 if (head < 0 || head >= strlen(tape)) {
 return 0; // Reject if the head goes out of bounds
 }
 }
}
int main() {
 char inputString[MAX_LENGTH];
 printf("Enter a string of 0s and 1s: ");
 scanf("%s", inputString);
 if (turingMachine(inputString)) {
 printf("Accepted\n");
 } else {
 printf("Rejected\n");
 }
 return 0;
}
