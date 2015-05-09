
#include <iostream>
using namespace std;

#define MAX 32768

bool che[MAX];
int prime[MAX];
int pc=0;

inline int cmp(const void* v1, const void* v2)
{
    return (*(int*)v1)-(*(int*)v2);
}

int main()
{
    int i, j, n;
    
    memset(che, true, MAX);
    for ( i=2 ; i<MAX ; ++i) {
        if ( che[i]==true ) {
            prime[pc++] = i;
            for ( j=i+i ; j<MAX ; j+=i )
                che[j] = false;
        }
    }

    int cnt, tmp, end;
    while ( cin >> n, n ) {
        cnt=0;
        for ( i=0, end=n/2 ; prime[i]<=end && i<pc ; ++i ) {
            tmp = n-prime[i];
            if ( bsearch(&tmp, prime, pc, sizeof(int), cmp) )
                ++cnt;
//          cout << prime[i] <<' ' << tmp << endl;
        }
        cout << cnt << endl;
    }
    return 0;
}