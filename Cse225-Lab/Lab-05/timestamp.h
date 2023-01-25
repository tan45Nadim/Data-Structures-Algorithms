#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

#include<iostream>
using namespace std;

class timeStamp {
    friend bool operator<(timeStamp, timeStamp);
    friend bool operator==(timeStamp, timeStamp);
private:
    int second;
    int minute;
    int hour;
public:
    timeStamp();
    timeStamp(int, int, int);
    void printTime();

};
#endif // TIMESTAMP_H_INCLUDED
