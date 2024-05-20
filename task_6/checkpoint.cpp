#include "checkpoint.h"

void CheckPoint::DisplayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "coordinates: (" << latitude << ", " << longitude << ")" << std::endl;
    if (penalty_time > 0) {
        std::cout<< "Penalty time: " << penalty_time << " h" << std::endl;
    }
    else {
        std::cout << "Failed SU" << std::endl;
    }
}
