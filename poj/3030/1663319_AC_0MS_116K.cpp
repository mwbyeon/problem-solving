
#include <iostream>
using namespace std;

int main()
{
    int T;
    int r, e, c;
    for ( cin >> T ; T-- ; ) {
        cin >> r >> e >> c;
        if ( r<e-c )
            cout << "advertise" << endl;
        else if ( r>e-c )
            cout << "do not advertise" << endl;
        else
            cout << "does not matter" << endl;
    }
    return 0;
}
