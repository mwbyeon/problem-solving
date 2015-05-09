#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

map< vector<int>, int> memo;

int solve(vector<int> cakes) {
    sort(cakes.begin(), cakes.end());

    if ( cakes.back() == 0 ) return 0;
    if ( memo.find(cakes) != memo.end() ) {
        return memo[cakes];
    }

    int minv = cakes.back();

    for ( int i=0 ; i<cakes.size() ; ++i ) {
        for ( int j=1 ; j<cakes[i] ; ++j ) {
            vector<int> next(cakes);
            next[i] = j;
            next.push_back(cakes[i] - j);
            minv = min(minv, solve(next) + 1);
        }
    }
    return memo[cakes] = minv;
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
        printf("Case #%d: %d\n", tc, solve(cakes));
    }

    return 0;
}