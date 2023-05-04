/*
#include <stdio.h>
#include <stdlib.h>
#include "forward_list.h"

ForwardList *forward_list_construct()
{
    ForwardList *l = (ForwardList *)malloc(sizeof(ForwardList));
    l->size = 0;
    l->head = NULL;
    return l;
}

int forward_list_size(ForwardList *l)
{
    return l->size;
}

void forward_list_push_front(ForwardList *l, data_type data)
{
    l->head = node_construct(data, l->head);
    l->size++;
}

void forward_list_print(ForwardList *l, void (*print_fn)(data_type))
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

data_type forward_list_get(ForwardList *l, int i)
{
    Node *n = l->head;
    for (; i > 0; i--)
        n = n->next;
    return n->value;
}

data_type forward_list_pop_front(ForwardList *l)
{
    Node *n = l->head;
    data_type d = n->value;
    l->head = l->head->next;
    node_destroy(n);
    return d;
}

ForwardList *forward_list_reverse(ForwardList *l)
{
    int i;
    Node *n = l->head;
    ForwardList *l2 = forward_list_construct();
    for (i = 0; i < l->size; i++)
    {
        forward_list_push_front(l2, n->value);
        n = n->next;
    }
    return l2;
}

void forward_list_remove(ForwardList *l, data_type val)
{
    Node *temp, *last = NULL, *n = l->head;
    while (n)
    {
        if (val == n->value)
        {
            if (last)
            {
                last->next = n->next;
                node_destroy(n);
                l->size--;
                n = last->next;
            }
            else
            {
                temp = n->next;
                node_destroy(n);
                l->size--;
                n = temp;
                l->head = n;
            }

            continue;
        }
        last = n;
        n = n->next;
    }
}

void forward_list_cat(ForwardList *l, ForwardList *m)
{
    Node *n = m->head;
    while (n)
    {
        forward_list_push_front(l, n->value);
        n = n->next;
    }
}

void forward_list_destroy(ForwardList *l)
{
    Node *t, *n = l->head;
    while (n)
    {
        t = n;
        n = n->next;
        node_destroy(t);
    }
    free(l);
}*/