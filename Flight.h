#ifndef Flight_H
#define Flight_H
#include <iostream>
#include <string>
#include "Date.h"
#include "time.h"
#include "timeLength.h"

using namespace std;

class Flight{
public:
    Flight(string, string, Time, Time, float);
    friend ostream& operator<<(ostream&, const Flight&);
    bool operator<(const Flight&);
    bool operator>(const Flight&);
    bool operator==(const Flight&);

    ~Flight();
private:
    string destination, departure;
    float cost;
    Time departure_time, arrival_time;
};
#endif