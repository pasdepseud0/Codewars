#include <stdbool.h>
#define NULL 0

typedef struct node {
  int data;
  struct node *prev, *next;
} node_t;

typedef struct deque {
  node_t *front, *back;
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
  if (next == deque->front) {
    deque->front = added;
    }
  if (prev == deque->back) {
    deque->back = added;
    }
}

int deque_remove_node(deque_t *deque, node_t *remove)
{
  if (remove == deque->back) {
    deque->back = remove->prev;
    }
  if (remove == deque->front) {
    deque->front = remove->next;
    }
  return free_node(unlink_node(remove));
}

void deque_push_front(deque_t *deque, int data)
{
  deque_add_node(deque, NULL, data, deque->front);
}

int deque_pop_front(deque_t *deque)
{
  return deque_remove_node(deque, deque->front);
}

int deque_peek_front(const deque_t *deque)
{
  return deque->front->data;
}

void deque_push_back(deque_t *deque, int data)
{
  deque_add_node(deque, deque->back, data, NULL);
}

int deque_pop_back(deque_t *deque)
{
  return deque_remove_node(deque, deque->back);
}

int deque_peek_back(const deque_t *deque)
{
  return deque->back->data;
}

bool deque_is_empty(const deque_t *deque)
{
  return !deque->front && !deque->back;
}