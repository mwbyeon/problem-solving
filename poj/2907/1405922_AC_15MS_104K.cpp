#include <iostream> 
using namespace std; 

int dp[11][11]; 
int beeper[11][2]; 
int shortest, bees; 

void traveling(int prev, bool visit[], int candi, int length) 
{ 
    if ( length>shortest ) return; 

    int tmp; 
    if ( candi==0 && (tmp=length+dp[prev][0])<shortest ) { 
        shortest = tmp; 
        return; 
    } 
     
    int i; 
    for ( i=1 ; i<bees ; ++i ) { 
        if ( !visit[i] ) { 
            visit[i] = true; 
            traveling(i, visit, candi-1, length+dp[prev][i]); 
            visit[i] = false; 
        } 
    } 
} 
     
int main() 
{ 
    int CASE; 
    int sz_x, sz_y; 
    int go_x, go_y; 
    int i, j; 
    bool visit[12], len; 
     
    for ( cin >> CASE ; CASE-- ; ) 
    { 
        cin >> sz_x >> sz_y; 
         
        cin >> beeper[0][0] >> beeper[0][1]; 

        memset(dp, 0, sizeof(dp)); 
        cin >> bees; 
        ++bees; 
        for ( i=1 ; i<bees ; ++i ) 
            cin >> beeper[i][0] >> beeper[i][1]; 
        for ( i=0 ; i<bees ; ++i ) { 
            for ( j=i ; j<bees ; ++j ) { 
                dp[i][j] = dp[j][i] = abs(beeper[i][0]-beeper[j][0])+abs(beeper[i][1]-beeper[j][1]); 
            } 
        } 

        memset(visit, false, sizeof(visit)); 
        visit[0] = true; 

        for ( i=1, shortest=dp[0][bees-1] ; i<bees ; ++i ) 
            shortest += dp[i][i-1]; 
         
        traveling(0, visit, bees-1, 0); 
         
        cout << "The shortest path has length " << shortest << endl; 
    } 
    return 0; 
} 
