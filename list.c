#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List *list_construct()
{
  List *l = (List *)malloc(sizeof(List));
  l->size = 0;
  l->head = NULL;
  l->last = NULL;
  return l;
}

int list_size(List *l)
{
  return l->size;
}

void list_push_front(List *l, data_type data)
{
  Node *n = node_construct(data, NULL, l->head);
  if (l->head)
  {
    l->head->prev = n;
    l->head = l->head->prev;
  }
  else
  {
    l->head = n;
    l->last = n;
  }
  l->size++;
}

void list_push_back(List *l, data_type data)
{
  Node *n = node_construct(data, l->last, NULL);
  if (l->last)
  {
    l->last->next = n;
    l->last = l->last->next;
  }
  else
  {
    l->head = n;
    l->last = n;
  }
  l->size++;
}

void list_print(List *l, void (*print_fn)(data_type))
{
  printf("[");
  Node *n = l->head;
  while (n)
  {
    print_fn(n->value);
    n = n->next;
    if (n)
      printf(", ");
  }
  printf("]");
}

void list_print_reverse(List *l, void (*print_fn)(data_type))
{
  printf("[");
  Node *n = l->last;
  while (n)
  {
    print_fn(n->value);
    n = n->prev;
    if (n)
      printf(", ");
  }
  printf("]");
}

data_type list_pop_front(List *l)
{
  Node *n = l->head;
  data_type d = n->value;
  l->head = l->head->next;
  if (l->head)
    l->head->prev = NULL;
  else
    l->last = NULL;
  node_destroy(n);
  return d;
}

data_type list_pop_back(List *l)
{
  Node *n = l->last;
  data_type d = n->value;
  l->last = l->last->prev;
  if (l->last)
    l->last->next = NULL;
  else
    l->head = NULL;
  node_destroy(n);
  return d;
}

void list_destroy(List *l)
{
  Node *t, *n = l->head;
  while (n)
  {
    t = n;
    n = n->next;
    node_destroy(t);
  }
  free(l);
}

ListIterator *list_front_iterator(List *l)
{
  ListIterator *it = malloc(sizeof(ListIterator));
  it->current = l->head;
  return it;
}

ListIterator *list_back_iterator(List *l)
{
  ListIterator *it = malloc(sizeof(ListIterator));
  it->current = l->last;
  return it;
}

data_type *list_iterator_next(ListIterator *it)
{
  data_type *d = &(it->current->value);
  it->current = it->current->next;
  return d;
}

data_type *list_iterator_previous(ListIterator *it)
{
  data_type *d = &(it->current->value);
  it->current = it->current->prev;
  return d;
}

bool list_iterator_is_over(ListIterator *it)
{
  return it->current == NULL;
}

void list_iterator_destroy(ListIterator *it)
{
  free(it);
}