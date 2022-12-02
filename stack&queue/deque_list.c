/*
** CODEWARS PROJECT, 2022
** deque_list.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>
#define NULL 0

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} node_t;

typedef struct deque {
  node_t *first;
  node_t *last;
} deque_t;

void link_two_nodes(node_t *prev, node_t *next)
{
  if (prev != NULL) {
    prev->next = next;
    }
  if (next != NULL) {
    next->prev = prev;
    }
}

void unlink_two_nodes(node_t *prev, node_t *next)
{
  if (prev && prev->next == next) {
    prev->next = NULL;
    }
  if (next && next->prev == prev) {
    next->prev = NULL;
    }
}

node_t *unlink_node(node_t *current)
{
  unlink_two_nodes(current->prev, current);
  unlink_two_nodes(current, current->next);
  return current;
}

node_t *link_three_nodes(node_t *prev, node_t *current, node_t *next)
{
  link_two_nodes(prev, current);
  link_two_nodes(current, next);
  return current;
}

node_t *make_node(int data)
{
  node_t *node = calloc(1, sizeof(node_t));
  node->data = data;
  return node;
}

node_t *free_node(node_t *node)
{
  int data = node->data;
  free(node);
  return data;
}

void deque_add_node(deque_t *deque, node_t *prev, int data, node_t *next)
{
  node_t *added = link_three_nodes(prev, make_node(data), next);
  if (next == deque->first) {
    deque->first = added;
    }
  if (prev == deque->last) {
    deque->last = added;
    }
}

int deque_remove_node(deque_t *deque, node_t *remove)
{
  if (remove == deque->last) {
    deque->last = remove->prev;
    }
  if (remove == deque->first) {
    deque->first = remove->next;
    }
  return free_node(unlink_node(remove));
}

void deque_push_first(deque_t *deque, int data)
{
  deque_add_node(deque, NULL, data, deque->first);
}

int deque_pop_first(deque_t *deque)
{
  return deque_remove_node(deque, deque->first);
}

int deque_peek_first(const deque_t *deque)
{
  return deque->first->data;
}

void deque_push_last(deque_t *deque, int data)
{
  deque_add_node(deque, deque->last, data, NULL);
}

int deque_pop_last(deque_t *deque)
{
  return deque_remove_node(deque, deque->last);
}

int deque_peek_last(const deque_t *deque)
{
  return deque->last->data;
}

bool deque_is_empty(const deque_t *deque)
{
  return !deque->first && !deque->last;
}