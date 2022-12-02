/*
** CODEWARS PROJECT, 2022
** queue_list.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct {
  node_t *first;
  node_t *last;
} tail_t;

bool queue_empty(const tail_t *queue) {
  return queue->first == 0; // when nobody is at front of the queue
}
void queue_enqueue(tail_t *queue, int data) {
  bool was_empty = queue_empty(queue);
  node_t *ptrnode = malloc(sizeof(node_t));
  ptrnode->data = data;
  ptrnode->next = NULL;
  if (!was_empty) queue->last->next = ptrnode; // link tail
  queue->last = ptrnode;
  if (was_empty) queue->first = ptrnode;
}
int queue_dequeue(tail_t *queue)
{
  node_t *ptrnode = queue->first;
  queue->first = ptrnode->next;
  if (queue_empty(queue)) queue->last = NULL;
  int data = ptrnode->data;
  free(ptrnode);
  return data;
}
int queue_first(const tail_t *queue)
{
  return queue->first->data;
}