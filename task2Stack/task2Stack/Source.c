#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct stack {
    char stck[MAX];
    int top;
}s;

int isFull() {
    if (s.top == (MAX - 1)) {
        return 1;
    }
    else return 0;
}

void push(char element) {
    if (isFull() == 1) {
        printf(" \nError overflow..stack is full!..you cannot add elements\n ");
    }
    else {
        s.top = s.top + 1;
        s.stck[s.top] = element;
    }
}
int isEmpty() {
    if (s.top == -1) {
        return 1;
    }
    else return 0;
}
void pop() {
    if (isEmpty() == 1) {
        printf("\n stack is empty\n");
    }
    else
        s.top = s.top - 1;
}

int checkPair(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}

int checkBalanced(char expr[], int len){
      
    for (int i = 0; i < len; i++)  //({})
    { 
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')  
        {  
          push(expr[i]); 
        } 
        else
        {
            
        if (s.top == -1) 
            return 0;
        else if(checkPair(s.stck[s.top],expr[i]))
        {
            pop();
            continue;
        }
       
        return 0;
        }
    }    
    return 1; 
}
int main() {
  char exp[MAX] = "({})";
  int i = 0;
  s.top = -1;

  int len = strlen(exp);
  checkBalanced(exp, len)?printf("Balanced Parenthesis"): printf("Not Balanced Parenthesis"); 

  return 0;
}