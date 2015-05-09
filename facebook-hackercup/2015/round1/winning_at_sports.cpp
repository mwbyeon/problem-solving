
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int memo[2048][2048];

int solve(int a, int b) {
    if ( a <= b ) return 0;
    if ( a == 0 ) return 1;
    if ( b == 0 ) return 1;

    int& res = memo[a][b];
    if ( res >= 0 ) return res;
    res = solve(a-1, b) + solve(a, b-1);
    res %= 1000000007;
    return res;
}

int main()
{
    //freopen("winning_at_sports_example_input.txt", "r", stdin);

    memset(memo, -1, sizeof(memo));

    int T;
    scanf("%d", &T);
    for ( int tc=1 ; tc<=T ; ++tc ) {
        int a, b;
        scanf("%d-%d", &a, &b);

        printf("Case #%d: %d %d\n", tc, solve(a, b), solve(b+1, b));
    }

    return 0;
}

