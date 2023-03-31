#pragma once
#include "std_lib_facilities.h"

class Point
{
    private:
    public:
        int x, y;
        Point() : x(0), y(0) {}
        Point(int x, int y) : x(x), y(y) {}

        friend ostream& operator<<(ostream& os, const Point& t);
        friend bool operator<(const Point& t1, const Point& t2);
};
