#include <iostream>
using namespace std;
 
int main()
{
    long long n, k, tot, rem;
 
    while ( cin >> n >> k ) {
        tot = n;
        rem = 0;
        while ( n ) {
            n += rem;
            rem = n%k;      
            n /= k;
            tot += n;
        }
        cout << tot << endl;
    }
    return 0;
}
