#include "checkpointbuilders.h"

void CheckPointBuilder::BuildCoordinates(const double latitude, const double longitude) {
    if (latitude < -90.0 || latitude > 90.0 || longitude < -180.0 || longitude > 180.0) {
        throw std::invalid_argument("Invalid latitude and longitude values");
    }
    check_point->SetLatitude(latitude);
    check_point->SetLongitude(longitude);
}
