#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct _node
{
    void *data;
    Node *next;
};

struct _list
{
    Node *head = nullptr;
};

List *list_create()
{
    List *list = (List *)malloc(sizeof(List));
    list->head = nullptr;
    return list;
}

void list_delete(List *list)
{
    for (int i = 0; i < list_get_length(list); i++)
    {
        Node *head = list->head;
        list->head = head->next;
        free(head);
    }

    free(list);
}

void list_add(List *list, void *data)
{
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = data;

    if (list->head == 0)
    {
        list->head = current;
        list->head->next = 0;
    }
    else
    {
        current->next = list->head;
        list->head = current;
    }
}

void list_insert_after(Node *node, void *data)
{
    Node *current = (Node *)malloc(sizeof(Node));

    current->data = data;
    current->next = node->next;
    node->next = current;
}

Node *list_get_first(List *list)
{
    return list->head;
}

Node *list_get_next(Node *node)
{
    return node->next;
}

void *list_get_data(Node *node)
{
    return node->data;
}

int list_get_length(List *list)
{
    int count = 0;

    Node *current = list->head;

    while (current != 0)
    {
        count++;
        current = current->next;
    }

    return count;
}
