/*
** CODEWARS PROJECT, 2022
** stack_list.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>
#include <stddef.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct stack {
  node_t *root;
} stack_t;

void stack_push(stack_t *stack, int data)
{
  node_t *newdata = malloc(sizeof(node_t));
  newdata->data = data;
  newdata->next = stack->root;
  stack->root = newdata;
}
int stack_pop(stack_t *stack)
{
  int result = stack->root->data;
  node_t *tmp = stack->root->next;
  free(stack->root);
  stack->root = tmp;
  return result;
}
int stack_peek(const stack_t *stack)
{
  return stack->root->data;
}
bool stack_is_empty(const stack_t *stack)
{
  return stack->root == NULL;
}