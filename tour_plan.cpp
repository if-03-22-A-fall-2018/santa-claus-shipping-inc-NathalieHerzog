#include "tour_plan.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

TourPlan *plan_createTour(ChildDataMgmt *cdm)
{
    _tourPlan *plan = (_tourPlan *)malloc(sizeof(_tourPlan));
    Node *current = cdm_get_sorted_data(cdm);

    CityPlan *crnt_city_plan;
    ChildData *crnt_child_data;
    ChildPlan *crnt_child_plan;

    plan->city_plans = list_create();
    char *prev_city = (char *)malloc(32);

    while (current != 0)
    {
        crnt_child_data = (ChildData *)list_get_data(current);

        if (strcmp(prev_city, crnt_child_data->city) != 0)
        {
            crnt_city_plan = (CityPlan *)malloc(sizeof(CityPlan));
            crnt_city_plan->city = crnt_child_data->city;
            crnt_city_plan->child_plans = list_create();
            list_add(plan->city_plans, crnt_child_plan);
        }

        prev_city = strcpy(prev_city, crnt_child_data->city);
        crnt_child_plan = data_as_plan(crnt_child_data);
        list_add(crnt_city_plan->child_plans, crnt_child_plan);
        plan->total_children++;
        plan->total_presents += crnt_child_plan->presents;
        current = list_get_next(current);
    }
    
    free(prev_city);
    return plan;
}

ChildPlan *data_as_plan(ChildData *child_data)
{
    ChildPlan *child_plan = (ChildPlan *)malloc(sizeof(ChildPlan));
    child_plan->name = child_data->name;
    child_plan->presents = plan_calc_presents(child_data->goodness);
    return child_plan;
}

void plan_print(TourPlan *plan)
{
    Node *node_city_plan = list_get_first(plan->city_plans);
    Node *node_child_plan;
    CityPlan *crnt_city_plan;
    ChildPlan *crnt_child_plan;

    printf("Shipping %d presents to %d children!\n", plan->total_presents, plan->total_children);
    while (node_city_plan != 0)
    {
        crnt_city_plan = (CityPlan *)list_get_data(node_city_plan);
        printf("***\n");
        printf("Shipment to %s:\n", crnt_city_plan->city);
        node_child_plan = list_get_first(crnt_city_plan->child_plans);

        while (node_child_plan != 0)
        {
            crnt_child_plan = (ChildPlan *)list_get_data(node_child_plan);
            printf("%s: %d presents\n", crnt_child_plan->name, crnt_child_plan->presents);
            node_child_plan = list_get_next(node_child_plan);
        }
        node_city_plan = list_get_next(node_city_plan);
    }
}

void plan_delete(TourPlan *plan)
{
    int length = list_get_length(plan->city_plans);
    Node *node_city_plan = list_get_first(plan->city_plans);

    for (int i = 0; i < length; i++)
    {
        list_delete(((CityPlan *)list_get_data(node_city_plan))->child_plans);
        node_city_plan = list_get_next(node_city_plan);
    }
    list_delete(plan->city_plans);
    free(plan);
}

int plan_calc_presents(double goodness)
{
    if (goodness <= 0.5)
    {
        return 0;
    }
    else if (goodness >= 1.0)
    {
        return 5;
    }
    else
    {
        return goodness * 10 - 5;
    }
}
