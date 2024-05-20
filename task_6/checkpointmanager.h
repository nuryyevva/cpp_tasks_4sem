#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include "checkpointbuilders.h"

class CheckPointManager
{
private:
    CheckPointBuilder* builder;

public:
    CheckPointManager() : builder(nullptr) {}
    std::shared_ptr<CheckPoint> ConstructCheckPoint(const std::string& name,
                                                    const double latitude, const double longitude,
                                                    const double penalty_time = 0);
    void SetBuilder(CheckPointBuilder* new_builder) { builder = new_builder; }
    std::shared_ptr<CheckPoint> GetCheckPoint() const { return builder->GetCheckPoint(); }
};

#endif // CHECKPOINTMANAGER_H
