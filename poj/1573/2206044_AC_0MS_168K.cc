#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;
 
int main()
{
    int row, col, pos;
    char grid[16][16];
    int table[16][16];
    int i, j, step;
    bool stoped;
 
    while ( cin >> row >> col >> pos, row || col || pos ) {
        memset(grid, 0x00, sizeof(grid));
        memset(table, 0x00, sizeof(table));
 
        for ( i=0 ; i<row ; ++i )
            for ( j=0 ; j<col ; ++j )
                table[i][j] = -1;


        for ( i=0 ; i<row ; ++i ) {
            scanf("%s", grid[i]);
        }

        stoped = false;
        for ( i=0, j=pos-1, step=0 ; i>=0 && i<row && j>=0 && j<col ; ++step ) {
            if ( table[i][j]>=0 ) {
                printf("%d step(s) before a loop of %d step(s)\n", table[i][j], step-table[i][j]);
                stoped = true;
                break;
            }
            else {
                table[i][j] = step;
                switch ( grid[i][j] ) {
                    case 'N': i--; break;
                    case 'E': j++; break;
                    case 'W': j--; break;
                    case 'S': i++; break;
                }
            }
        }

        if ( !stoped ) {
            printf("%d step(s) to exit\n", step);
        }
    }
    return 0;
}
