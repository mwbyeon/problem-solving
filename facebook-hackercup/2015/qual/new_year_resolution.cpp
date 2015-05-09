#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for ( int tc=1 ; tc<=T ; ++tc ) {
        int gp, gc, gf;
        cin >> gp >> gc >> gf;

        int N;
        cin >> N;

        vector<int> P(N), C(N), F(N);
        for ( int i=0 ; i<N ; ++i ) {
            cin >> P[i] >> C[i] >> F[i];
        }

        bool ok = false;
        for ( int m=0 ; m<(1<<N) ; ++m ) {
            int p = 0, c = 0, f = 0;
            for ( int k=0 ; k<N ; ++k ) {
                if ( m & (1<<k) ) {
                    p += P[k];
                    c += C[k];
                    f += F[k];
                }
            }
            if ( p == gp && c == gc && f == gf ) {
                ok = true;
            }
        }

        printf("Case #%d: %s\n", tc, ok ? "yes" : "no");
    }

    return 0;
}