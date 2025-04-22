#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node *next;
};
typedef struct Node Node ;

Node *CreateNode(char data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void Push(Node** top, char data) {
  Node *node = CreateNode(data);
  node->next = *top;
  *top = node;
}

char Pop(Node** top) {
  if (*top == NULL) {
    return '\0';
  }

  char data = (*top)->data;
  Node *temp = *top;
  *top = (*top)->next;
  free(temp);
  return data;
}

int IsPaired(char p1, char p2) {
  return (p1 == '(' && p2 == ')') || (p1 == '{' && p2 == '}') || (p1 == '[' && p2 == ']');
}

int IsBalanced(const char* p, size_t n) {
  Node* top = NULL;

  for (size_t i = 0; i < n; i++) {
    if (p[i] == '(' || p[i] == '{' || p[i] == '[') {
      Push(&top, p[i]);
    } else if (p[i] == ')' || p[i] == '}' || p[i] == ']') {
      char p2 = Pop(&top);
      if (!IsPaired(p2, p[i])) {
        return 0;
      }
    }
  }

  if (top != NULL) {
    return 0;
  }

  return 1;
}

int main() {

  char p[] = "({()}[])(((";

  int balanced = IsBalanced(p, sizeof(p) / sizeof(char));

  if (balanced) {
    printf("Parantezler dengeli.\n");
  } else {
    printf("Parantezler dengesiz.\n");
  }

  return 0;
}
