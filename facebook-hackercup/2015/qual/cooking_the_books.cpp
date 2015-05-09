
#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        string num;
        cin >> num;
        int len = num.length();
        int minv = atoi(num.c_str()), maxv = atoi(num.c_str());
        for ( int i=0 ; i<len ; ++i ) {
            for ( int j=i+1 ; j<len ; ++j ) {
                if ( num[j] != '0' ) {
                    swap(num[i], num[j]);
                    minv = min(minv, atoi(num.c_str()));
                    maxv = max(maxv, atoi(num.c_str()));
                    swap(num[i], num[j]);                    
                }
            }
        }
        printf("Case #%d: %d %d\n", tc, minv, maxv);
    }
    return 0;
}