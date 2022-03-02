#include "game3d.h"  // my game library
#include <array>     // for array container
#include <cmath>     // for pow(), sqrt() function
#include <iomanip>   // for formatted output
#include <iostream>


/**
* @brief calculates distance between two points and prints statement stating distance between two points
* @param status: doubles points a and b
*/
double game3d::Distance(double point_a, double point_b)
{
    double distance = 0;

    // Calculate difference and save it in the distance variable
    distance = fabs(point_b - point_a);
    // Set fixed precision of 2 decimal places
    std::cout << std::fixed << std::setprecision(2);
    // Output message
    std::cout << "Distance between " << point_a << " and " << point_b << " = " << distance << std::endl;

    return distance;
}

/**
* @brief adds distances to total
*
* @param status: array of doubles
*/
double game3d::TotalWalkingDistance(const std::array<double, kMaxPoints> &locations)
{
    double total = 0;
    // loop over all elements
    for (int i = 0; i < kMaxPoints - 1 ; i++)
    {
// call Distance function and save it in total variable
       total += Distance(locations[i], locations[i+1]);
    }

    return total;
}

// part 2
// game3d.cpp
/**
* @brief determines if within radius of safeness
*
* @param status: doubles points 1 and 2
*/
bool game3d::SafeToTravel(double point1, double point2)
{
    bool safe = true;
    // Calculate Distance
    auto SafeTravel = Distance(point1, point2);
    // Determine if it is safe to travel
    if (SafeTravel >= kSafeRadius )
    {
        safe = true;

    } else
    {
        safe = false;
    }
    SafeToTravelMessage(safe);
    return safe;
}

/**
* @brief Print message if it is safe to move to another point
*
* @param status: true or false
*/
void game3d::SafeToTravelMessage(bool status)
{
    std::cout << "Should I move? " << std::endl;
    if (status)
    {
        std::cout << "\tYes, you are in the safe zone" << std::endl;
    }
    else
    {
        std::cout << "\tNo, stay put. You are in the danger zone" << std::endl;
    }
}
/**
* @brief if it is safe to travel the distance is added to the total
*
* @param status: array of doubles
*/

double game3d::TotalSafeWalkingDistance(const std::array<double, kMaxPoints> &locations)
{
    double total = 0;
    // loop over all elements
    for (int i = 0; i < kMaxPoints-1 ; i++)
    {
        if (SafeToTravel(locations[i], locations[i+1]) == true )
        {
            total += Distance(locations[i], locations[i+1]);
        }


    }


    return total;
}

// Part 3: Overload functions
// Default input parameters are only defined in the header file.
/**
* @brief calcultes three dimensional distance
*
* @param status: arrays of doubles a and b
*/
double game3d::Distance(std::array<double, game3d::kDimensions> a,
                        std::array<double, game3d::kDimensions> b)
{

    // Formula to calculate the distance between two 3D points:
    // distance = square root of ( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )

    // square root function: std::sqrt(expression)
    // power function: std::pow(x, 2) == x^2
    double distance = 0;
    // Calcuate distance here
    distance = std::sqrt(std::pow(b[0] - a[0], 2) + std::pow(b[1]-a[1], 2) + std::pow(b[2] - a[2],2));
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tDistance between (" << a[0] << "," << a[1] << "," << a[2] << ") and (" << b[0]
              << "," << b[1] << "," << b[2] << ") = " << distance << std::endl;

    return distance;
}
/**
* @brief adds three dimensional distance to a total
*
* @param status: array of doubles
*/
double game3d::TotalWalkingDistance(
        const std::array<std::array<double, game3d::kDimensions>, game3d::kMaxPoints> &locations)
{
    float total = 0;
    // loop over all elements
    for (int i = 0; i < kMaxPoints - 1 ; i++)
    {
        total += Distance(locations[i], locations[i + 1]);
    }

    return total;
}
