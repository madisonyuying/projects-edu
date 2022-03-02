#ifndef GAME_3D_H
#define GAME_3D_H

#include <array>

namespace game3d {
// namespace constants
    const int kDimensions = 3;

// Task 1
// Part 1
// Default input parameters are only defined in the header file.
    double Distance(double point_a, double point_b = 0);

    const int kMaxPoints = 10;
    const double kSafeRadius = 12.0;

    double TotalWalkingDistance(const std::array<double, kMaxPoints> &locations);

// Task 2:
    bool SafeToTravel(double point1, double point2 = 0);

    void SafeToTravelMessage(bool status);

    double TotalSafeWalkingDistance(const std::array<double, kMaxPoints> &locations);

// Task 3: Overload functions
    double Distance(std::array<double, kDimensions> a, std::array<double, kDimensions> b = {0, 0, 0});

    double TotalWalkingDistance(const std::array<std::array<double, kDimensions>, kMaxPoints> &locations);
    // namespace game3d
}
#endif

