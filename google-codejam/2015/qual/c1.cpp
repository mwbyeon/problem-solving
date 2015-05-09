#include <iostream>
#include <vector>
using namespace std;

int table[][4] = { 
  //  0, 1, 2, 3, 4, 5, 6, 7
  //  1, i, j, k,-1,-i,-j,-k
    { 0, 1, 2, 3 }, // 1, 
    { 1, 4, 3, 6 }, // i, 
    { 2, 7, 4, 1 }, // j, 
    { 3, 2, 5, 4 }, // k, 
    { 4, 5, 6, 7 }, // -1, 
    { 5, 0, 7, 2 }, // -i, 
    { 6, 3, 0, 5 }, // -j, 
    { 7, 6, 1, 0 }, // -k, 
};

bool solve(int L, int X, string str) {
    vector<int> vec(L);
    for ( int i=0 ; i<L ; ++i ) {
        if ( str[i] == 'i' ) vec[i] = 1;
        if ( str[i] == 'j' ) vec[i] = 2;
        if ( str[i] == 'k' ) vec[i] = 3;
    }
    const int len = L * X;
    int ii = 0;
    for ( int i=0 ; i<len ; ++i ) {
        const int k = i % L;
        ii = table[ii][vec[i%L]];
        if ( ii == 1 ) {
            int jj = 0;
            for ( int j=i+1 ; j<len ; ++j ) {
                jj = table[jj][vec[j%L]];
                if ( jj == 2 ) {
                    int kk = 0;
                    for ( int k=j+1 ; k<len ; ++k ) {
                        kk = table[kk][vec[k%L]];
                    }
                    if ( kk == 3 ) return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        int L, X;
        string str;
        cin >> L >> X >> str;
        printf("Case #%d: %s\n", tc, solve(L, X, str) ? "YES" : "NO");
    }

    return 0;
}