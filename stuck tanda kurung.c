#include <stdio.h>
#include <stdlib.h>

//berfungsi untuk membuat sebuah tipe data baru
typedef struct Stack {
    char data;
    struct Stack* next;
} Stack;

void push(Stack** top, char data) {
    Stack* new_node = (Stack*) malloc(sizeof(Stack));
    if (!new_node) return;
    new_node->data = data;
    new_node->next = (*top);
    (*top) = new_node;
}
//fungsi untuk memeriksa  apakah stuck kosong
int isEmpty(Stack* top) {
    return top == NULL;
}

char pop(Stack** top) {
    char popped;
    Stack* temp;
    if (isEmpty(*top)) return '\0';
    temp = *top;
    *top = (*top)->next;
    popped = temp->data;
    free(temp);
    return popped;
}

char peek(Stack* top) {
    if (isEmpty(top)) return '\0';
    return top->data;
}
// memeriksa apakah urutan tanda kurung sesuai
int isMatchingPair(char character1, char character2) {
   if (character1 == '(' && character2 == ')') return 1;
   else if (character1 == '{' && character2 == '}') return 1;
   else if (character1 == '[' && character2 == ']') return 1;
   else return 0;
}

int isBalanced(char exp[]) {
    int i = 0;
    Stack* stack = NULL;
    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&stack, exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (stack == NULL) return 0;
            else if (!isMatchingPair(pop(&stack), exp[i])) return 0;
        }
        i++;
    }
    if (stack == NULL) return 1;
    else return 0;
}

int main() {
    char exp[100];
    printf("Masukkan urutan tanda kurung: ");
    scanf("%s", exp);
    if (isBalanced(exp))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}