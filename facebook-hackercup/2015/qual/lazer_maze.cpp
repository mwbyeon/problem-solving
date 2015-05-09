#include <iostream>
#include <queue>
using namespace std;

struct Move {
    int r, c;
    int steps;
    Move(int _r, int _c, int _s) : r(_r), c(_c), steps(_s) { }
};

int main()
{
    int T;
    cin >> T;

    // < ^ > v
    const string direction = "<^>v";
    const int dr[] = { 0, -1, 0, 1 };
    const int dc[] = { -1, 0, 1, 0 };

    for ( int tc=1 ; tc<=T ; ++tc ) {
        int M, N;
        cin >> M >> N;

        char grid[M][N];
        int si, sj, ti, tj;
        for ( int i=0 ; i<M ; ++i ) {
            cin >> grid[i];
            for ( int j=0 ; j<N ; ++j ) {
                if ( grid[i][j] == 'S' ) {
                    si = i;
                    sj = j;
                    grid[i][j] = '.';
                }
                if ( grid[i][j] == 'G' ) {
                    ti = i;
                    tj = j;
                    grid[i][j] = '.';
                }
            }
        }

        int laser[M][N][4];
        memset(laser, 0, sizeof(laser));

        for ( int i=0 ; i<M ; ++i ) {
            for ( int j=0 ; j<N ; ++j ) {
                int dir = direction.find_first_of(grid[i][j]);
                if ( dir >= 0 ) {
                    for ( int k=0 ; k<4 ; ++k ) {
                        int di = (dir + k) % 4;
                        int r = i;
                        int c = j;
                        while ( true ) {
                            r += dr[di];
                            c += dc[di];
                            if ( r >= M || r < 0 || c >= N || c < 0 ) break;

                            if ( (r != i || c != j) && direction.find_first_of(grid[r][c]) != -1 ) break;
                            if ( grid[r][c] == '#' ) break;
                            laser[r][c][k] = 1;
                        }
                    }
                }
            }
        }

        /*
        puts("");
        for ( int i=0 ; i<M ; ++i ) {
            for ( int j=0 ; j<N ; ++j ) {
                for ( int k=0 ; k<4 ; ++k ) {
                    printf("%d", laser[i][j][k]);
                }
                printf(" ");
            }
            printf("\n");
        }
        */

        int visited[M][N][4];
        memset(visited, 0, sizeof(visited));
        queue<Move> queue;
        queue.push(Move(si, sj, 0));
        visited[si][sj][0] = 1;
        int res = -1;
        while ( !queue.empty() && res < 0 ) {
            Move curr = queue.front(); queue.pop();
            for ( int k=0 ; k<4 ; ++k ) {
                Move next(curr);
                next.r += dr[k];
                next.c += dc[k];
                next.steps += 1;
                if ( next.r < M && next.r >= 0 && next.c < N && next.c >=0 && grid[next.r][next.c] == '.' && !visited[next.r][next.c][next.steps % 4] ) { 
                    visited[next.r][next.c][next.steps % 4] = 1;
                    if ( !laser[next.r][next.c][next.steps % 4] ) {
                        if ( next.r == ti && next.c == tj ) {
                            res = next.steps;
                            break;
                        }
                        queue.push(next);
                    }
                }
            }
        }

        printf("Case #%d: ", tc);
        if ( res == -1 ) {
            printf("impossible\n");
        }
        else {
            printf("%d\n", res);
        }
    }

    return 0;
}