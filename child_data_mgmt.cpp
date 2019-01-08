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
    if (data == 0)
    {
        return;
    }

    Node *current = list_get_first(cdm->kids);

    if (current != 0)
    {
        _childData *currentD = (_childData *)list_get_data(current);
        Node *prev = 0;

        while (current != 0 && strcmp(currentD->city, data->city) <= 0)
        {
            prev = current;
            current = list_get_next(current);
            if (current != 0)
            {
                currentD = (ChildData *)list_get_data(current);
            }
        }

        if (prev != 0)
        {
            list_insert_after(prev, data);
        }
    }
    else
    {
        list_add(cdm->kids, data);
    }
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
