#include "child_data_mgmt.h"
#include <stdlib.h>
#include <string.h>

ChildDataMgmt *cdm_create()
{
    _childDataMgmt *child = (_childDataMgmt *)malloc(sizeof(_childDataMgmt));
    child->kids = list_create();

    return child;
}

void cdm_add_data(ChildDataMgmt *cdm, ChildData *data)
{
    Node *current = list_get_data(cdm);
    _childData *current = (_childData *)list_get_data(list_get_first(cdm->kids));

    while (current != 0 && strcmp(current->city, data->city) <= 0)
    {

    }

    current->data = data;
    current->next = list->head;
    list->head = current;
    
}

Node *cdm_get_sorted_data(ChildDataMgmt *cdm)
{
    return list_get_first(cdm->kids);
}

void cdm_delete(ChildDataMgmt *cdm)
{
    list_delete(cdm->kids);
    free(cdm);
}
