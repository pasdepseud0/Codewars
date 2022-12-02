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
  node_t *front, *back;
} queue_t;

bool queue_is_empty(const queue_t *queue) {
  return queue->front == 0; // when nobody is at front of the queue
}
void queue_enqueue(queue_t *queue, int data) {
  bool was_empty = queue_is_empty(queue);
  node_t *pnode = malloc(sizeof(node_t));
  pnode->data = data;
  pnode->next = NULL;
  if (!was_empty) queue->back->next = pnode; // link tail
  queue->back = pnode;
  if (was_empty) queue->front = pnode;
}
int queue_dequeue(queue_t *queue) {
  node_t *pnode = queue->front;
  queue->front = pnode->next;
  if (queue_is_empty(queue)) queue->back = NULL;
  int data = pnode->data;
  free(pnode);
  return data;
}
int queue_front(const queue_t *queue) {
  return queue->front->data;
}