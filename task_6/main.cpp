#include <iostream>

#include "checkpointmanager.h"

int main()
{
    OptionalCheckPointBuilder builder_opt;
    ObligatoryCheckPointBuilder builder_obl;
    CheckPointManager manager;

    // Creation of an obligatory check point
    manager.SetBuilder(&builder_obl);
    std::shared_ptr<CheckPoint> cp1 = manager.ConstructCheckPoint("required CP", 45.0, 30.0);

    // Creation of an optional check point
    manager.SetBuilder(&builder_opt);
    std::shared_ptr<CheckPoint> cp2 = manager.ConstructCheckPoint("optional CP", 60.0, 40.0, 1.5);

    std::cout << "List CP:" << std::endl;
    cp1->DisplayInfo();
    std::cout << std::endl;
    cp2->DisplayInfo();

    double total_penalty = 0;
    if (cp1->GetPenaltyTime() > 0) {
        total_penalty += cp1->GetPenaltyTime();
    }
    std::cout << std::endl;
    if (cp2->GetPenaltyTime() > 0) {
        total_penalty += cp2->GetPenaltyTime();
    }

    std::cout << "Total penalty: " << total_penalty << " h" << std::endl;
    return 0;
}
