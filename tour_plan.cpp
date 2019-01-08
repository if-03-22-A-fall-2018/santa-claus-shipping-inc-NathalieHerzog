#include "tour_plan.h"

TourPlan* plan_createTour(ChildDataMgmt *cdm)
{
    return (ChildData*)malloc(sizeof(ChildData))
}

void plan_print(TourPlan *plan)
{

}

void plan_delete(TourPlan *plan)
{

}

int plan_calc_presents(double goodness)
{
    if(goodness <= 0.5)
    {
        return 0;
    }
    else if(goodness >= 1.0)
    {
        return 5;
    }
    else
    {
        return goodness*10-5;
    }
}
