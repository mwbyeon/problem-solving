
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int solve1(int R, int C, int N) {
  if ( R > C ) swap(R, C);

  const int sz = R * C;
  int res = INT_MAX;
  int best = -1;
  for ( int m=0 ; m<(1<<sz) ; ++m ) {
    if ( __builtin_popcount(m) != N ) continue;

    int board[R+1][C+1];
    memset(board, 0, sizeof(board));

    for ( int i=0 ; i<sz ; ++i ) {
      if ( m & (1<<i) ) {
        int r = i / C;
        int c = i % C;
        board[r][c] = 1;
      }
    }

    int share = 0;
    for ( int i=0 ; i<R ; ++i ) {
      for ( int j=0 ; j<C ; ++j ) {
        if ( board[i][j] ) {
          if ( board[i+1][j] ) ++share;
          if ( board[i][j+1] ) ++share;
        }
      }
    }
    if ( res > share ) {
      res = share;
      best = m;
    }
  }

  for ( int i=0 ; i<R ; ++i ) {
    for ( int j=0 ; j<C ; ++j ) {
      printf("%d ", (best & (1<<(i * C + j))) > 0 ? 1 : 0);
    }
    puts("");
  }
  return res;
}

int main() {
  int TC;
  cin >> TC;
  for ( int tc=1 ; tc<=TC ; ++tc ) {
    int R, C, N;
    cin >> R >> C >> N;
    printf("Case #%d: %d\n", tc, solve1(R, C, N));
  }
}

