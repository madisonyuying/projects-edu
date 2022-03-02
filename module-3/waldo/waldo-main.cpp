#include <iostream>
#include "utilities.h"
#include <fstream>
#include <iomanip>


using namespace std;

int main() {
    string story;
    ifstream readWaldo("../../story.txt");
    if (readWaldo.fail())
    {
        cout << "Unable to open file.\n";
        return 1;
    }
   getline(readWaldo, story);
   story = FixStory(story);
   cout << story << endl;
   ofstream updated_story("../../updated_story.txt");
   updated_story << story << endl;
   updated_story.close();


    float magnitude;
    std::string type;
    std::string location;
    float latitude;
    float longitude;
    float depth;
    std::string time;


   ofstream  out_report("../../earthquake_report.txt");
   ifstream fin("../../earthquakes.txt");
   while (fin >> magnitude)
   {
       fin.ignore();
       getline(fin, type);
       getline(fin, location);
       fin >> latitude;
       fin >> longitude;
       fin >> depth;
       fin.ignore();
       fin >> time;


       out_report
       << right << setw(7) << "Magnitude"
       << left << setw(38) << "Location"
       << right << setw(12) << "Latitude"
       << setw(12) << "Longitude"
       << setw(8) << "Depth"
       << "  " << "Time" << endl;
       WriteReportLine(magnitude, type, location, latitude, longitude, depth, time, out_report);

   }
