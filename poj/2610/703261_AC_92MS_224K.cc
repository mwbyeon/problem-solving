#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct {
    double x, y;
} point;

double dis(point a, point b)
{
    return sqrt( pow(a.x-b.x,2)+pow(a.y-b.y,2) );
}

int main()
{
    int n;
    point dog, gopher, hole;

    bool flag = false;
    cin >> gopher.x >> gopher.y >> dog.x >> dog.y;
    while ( cin >> hole.x >> hole.y )
    {
        if ( dis(dog,hole) >= 2*dis(gopher,hole) ) {
            flag = true;
            break;
        }
    }
    if ( flag )
        printf("The gopher can escape through the hole at (%.3f,%.3f).\n", hole.x, hole.y);
    else
        printf("The gopher cannot escape.\n");
}

