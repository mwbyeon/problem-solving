#include <iostream>
using namespace std;

bool solve(int X, int R, int C) {
    if ( X == 1 ) return true;

    if ( X == 2 ) {
        if ( R * C < 1 * 2 ) return false;
    }
    if ( X == 3 ) {
        if ( R * C < 3 * 2 ) return false;
    }
    if ( X == 4 ) {
        if ( R * C < 4 * 3 ) return false;
    }
    return (R * C) % X == 0;
}

int main()
{
    /*
    for ( int i=1 ; i<=4 ; ++i ) {
        for ( int j=1 ; j<=4 ; ++j ) {
            for ( int k=1 ; k<=4 ; ++k ) {
                printf("X=%d R=%d C=%d : %d\n", i, j, k, solve(i, j, k));
            }
        }
    }
    */

    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        int X, R, C;
        cin >> X >> R >> C;
        printf("Case #%d: %s\n", tc, solve(X, R, C) ? "GABRIEL" : "RICHARD");
    }

    return 0;
}