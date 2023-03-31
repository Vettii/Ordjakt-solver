#include "ownpoint.h"

ostream& operator<<(ostream& os, const Point& t)
        {
        os << "(" << t.x << "," << t.y << ")";
        return os;
        }

bool operator<(const Point& t1, const Point& t2)
{
        if (t1.x == t2.x) {
                return (t1.y < t2.y);
        }
        else {
                return (t1.x < t2.x);
        }
}

