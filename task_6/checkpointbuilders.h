#ifndef CHECKPOINTBUILDER_H
#define CHECKPOINTBUILDER_H

#include <memory>

#include "checkpoint.h"


class CheckPointBuilder {
protected:
    std::shared_ptr<CheckPoint> check_point;
public:
    CheckPointBuilder() = default;
    virtual ~CheckPointBuilder() {}

    std::shared_ptr<CheckPoint> GetCheckPoint() const { return check_point; }
    void CreateNewCheckPoint() { check_point.reset(new CheckPoint); }

    void BuildName(const std::string& name) { check_point->SetName(name); }
    void BuildCoordinates(const double latitude, const double longitude);
    virtual void BuildPenaltyTime(const double penalty_time) = 0;
    std::shared_ptr<CheckPoint> GetResult() const { return check_point; }
};


class OptionalCheckPointBuilder : public CheckPointBuilder {
public:
    OptionalCheckPointBuilder() : CheckPointBuilder() {}
    void BuildPenaltyTime(const double penalty_time) override { check_point->SetPenaltyTime(penalty_time); }
};

class ObligatoryCheckPointBuilder : public CheckPointBuilder {
public:
    ObligatoryCheckPointBuilder() : CheckPointBuilder() {}
    void BuildPenaltyTime(const double) override { check_point->SetPenaltyTime(0); }
};

#endif // CHECKPOINTBUILDER_H
