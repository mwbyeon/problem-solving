#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int solve(set<int> cakes) {
    int special = 0;
    while ( cakes.size() > 1 ) {
        int maxv = *cakes.rbegin();
    }
    return special + *cakes.begin();
}

int main()
{
    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        int D;
        cin >> D;

        vector<int> cakes(D);
        for ( int i=0 ; i<D ; ++i ) {
            cin >> cakes[i];
        }
        printf("Case #%d: %d\n", tc, solve(set<int>(cakes.begin(), cakes.end())));
    }

    return 0;
}