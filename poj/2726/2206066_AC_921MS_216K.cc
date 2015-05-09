#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <vector>
using namespace std;
 
#define MAX 10001
 
typedef struct {
    int d, c;
} HOTEL;
 
bool cmp(HOTEL h1, HOTEL h2) {
    if ( h1.d==h2.d ) 
        return h1.c<h2.c;
    return h1.d<h2.d;
}
 
int main()
{
    int n;
    HOTEL hotel[MAX];
    bool check[MAX];
    int i, j;
 
    while ( scanf("%d", &n), n ) {
        for ( i=0 ; i<n ; ++i )
            scanf("%d %d", &hotel[i].d, &hotel[i].c);
 
        sort(hotel, hotel+n, cmp);
//    for ( i=0 ; i<n ; ++i )
//      printf("%d %d\n", hotel[i].d, hotel[i].c);
 
        memset(check, true, sizeof(check));
        for ( i=0 ; i<n ; ++i ) {
            if ( check[i] ) {
                for ( j=i+1 ; j<n ; ++j ) {
                    if ( hotel[i].d==hotel[j].d && hotel[i].c<hotel[j].c )
                        check[j] = false;
                    if ( hotel[i].d!=hotel[j].d && hotel[i].c<=hotel[j].c )
                        check[j] = false;
                }
            }
        }
        printf("%d\n", count(check, check+n, true));
    }
    return 0;
}