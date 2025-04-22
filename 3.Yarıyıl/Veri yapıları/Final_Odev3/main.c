#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

Node* CreateNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void KuyrugaEkle(Node** head, int data) {
    Node* node = CreateNode(data);
    node->next = *head;
    *head = node;
}

int KuyruktanAl(Node** head) {
    if (*head == NULL) {
        return -1;
    }

    int data = (*head)->data;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
}

int IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int EvaluatePrefixExpression(char* expression) {
    Node* head = NULL;

    for (int i = strlen(expression) - 1; i >= 0; i--) {
        if (IsOperator(expression[i])) {
            int operand1 = KuyruktanAl(&head);
            int operand2 = KuyruktanAl(&head);

            // Operatörün sonucunu hesaplar
            int result = 0;
            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            KuyrugaEkle(&head, result);
        } else {
            KuyrugaEkle(&head, expression[i] - '0');
        }
    }

    if (head != NULL) {
        return head->data;
    }

    return -1;
}

int main() {
    char expression[] = "+*9+28*+4863";

    int result = EvaluatePrefixExpression(expression);

    printf("Ifadenin degeri: %d\n", result);

    return 0;
}
