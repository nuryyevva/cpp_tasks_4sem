#include "checkpointmanager.h"

std::shared_ptr<CheckPoint> CheckPointManager::ConstructCheckPoint(const std::string& name,
                                                                   const double latitude, const double longitude,
                                                                   const double penalty_time) {
    builder->CreateNewCheckPoint();
    builder->BuildName(name);
    builder->BuildCoordinates(latitude, longitude);
    builder->BuildPenaltyTime(penalty_time);
    return builder->GetResult();
}
