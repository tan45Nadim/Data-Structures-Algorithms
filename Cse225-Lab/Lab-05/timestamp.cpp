#include "timestamp.h"
timeStamp::timeStamp() {
    second = 0;
    minute = 0;
    hour = 0;
}
timeStamp::timeStamp(int s, int m, int h) {
    second = s;
    minute = m;
    hour = h;
}

void timeStamp::printTime() {
    cout<<second<<":"<<minute<<":"<<hour<<endl;
}

bool operator<(timeStamp ts1, timeStamp ts2) {
//    if(ts1.hour < ts2.hour)
//        return true;
//    else if (ts1.hour > ts2.hour)
//        return false;
//    else
//    {
//        if (ts1.minute < ts2.minute)
//            return true;
//        else if (ts1.minute > ts2.minute)
//            return false;
//        else
//        {
//            if (ts1.second < ts2.second)
//                return true;
//            else
//                return false;
//        }
//    }
}

bool operator==(timeStamp ts1, timeStamp ts2) {
    if(ts1.hour == ts2.hour)
    {
        if(ts1.minute == ts2.minute)
            return ts1.second == ts2.second;
        else
            return false;
    }
    else
        return false;
}
