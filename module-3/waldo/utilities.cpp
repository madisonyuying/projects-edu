#include<array>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;
/**
 * @brief reads through the story. if file fails to open prints message to console
 *
 * @return reads story no return value
 */


string FixStory( string readWaldo )
{
    int location = readWaldo.find("&apos");
    while (location != string::npos)
    {
        readWaldo.replace(location, 6, "'");
        location = readWaldo.find("&apos");
    }
    int position = readWaldo.find("striped shirt");
    while (position != string::npos)
    {
        readWaldo.insert(position, "red ");
        position = position + 11;
        position = readWaldo.find("striped shirt", position);
    }
    return readWaldo;
}
/**
 * @brief receives parameters and prints a report
 *
 * @return magnitude, a float; magnitude type, a string; location, a string; latitude, a float;
   longitude, a float; depth, a float; time, a string; out, an ostream object passed by reference
*/
void
WriteReportLine(float magnitude, std::string type, std::string location, float latitude, float longitude, float depth,
                std::string time, std::ostream& out)

{
    std::string location_to_print;

    if (location.length()> 38)
    {
        location_to_print = location.substr(0, 35) + "...";
        } else {
            location_to_print = location;
    }
    out
        << std::right << std::setw(3) << std::fixed << std::setprecision(1) << magnitude << " "
        << std::left << std::setw(4) << type
        << std::setw(38) << location_to_print
        << std::right << std::setw(12) << std::fixed << std::setprecision(4) << latitude
        << std::setw(12) << std::fixed << std::setprecision(4) << longitude
        << std::setw(8) << std::fixed << std::setprecision(1) << depth << "  "
        << time <<
std::endl;

}



