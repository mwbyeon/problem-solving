
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    //freopen("homework_example_input.txt", "r", stdin);

    const int MAXN = 10000100;

    vector<bool> prime(MAXN, true);
    for ( int i=4 ; i<MAXN ; i+=2 ) {
        prime[i] = false;
    }
    for ( int i=3 ; i<MAXN ; i+=2 ) {
        for ( int k=i+i ; k<MAXN ; k+=i ) {
            prime[k] = false;
        }
    }

    vector<int> primacity(MAXN, 0);
    for ( int i=2 ; i<MAXN ; ++i ) {
        if ( prime[i] ) {
            for ( int k=i ; k<MAXN ; k+=i ) {
                primacity[k]++;
            }
        }
    }

    int T;
    scanf("%d", &T);
    for ( int tc=1 ; tc<=T ; ++tc ) {
        int A, B, K;
        scanf("%d %d %d", &A, &B, &K);
        int res = 0;
        for ( int i=A ; i<=B ; ++i ) {
            if ( primacity[i] == K ) {
                ++res;
            }
        }
        printf("Case #%d: %d\n", tc, res);
    }
    return 0;
}

