#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <string>
#include <iostream>

class CheckPoint {
private:
    std::string name;
    double latitude;
    double longitude;
    double penalty_time;

public:
    CheckPoint() = default;
    void SetName(const std::string& new_name) { name = new_name; }
    void SetLatitude(const double new_latitude) { latitude = new_latitude; }
    void SetLongitude(const double new_longitude) { longitude = new_longitude; }
    void SetPenaltyTime(const double new_penalty_time) { penalty_time = new_penalty_time; }

    double GetPenaltyTime() const { return penalty_time; }

    void DisplayInfo() const;
};


#endif // CHECKPOINT_H
