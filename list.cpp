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
    free(list);
}

void list_add(List *list, void *data)
{
    Node *current = (Node *)malloc(sizeof(Node));

    current->data = data;
    current->next = list->head;
    list->head = current;
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
    if (node->next == 0)
    {
        return node;
    }

    return node->next;
}

void *list_get_data(Node *node)
{
    return node->data;
}
