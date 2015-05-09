#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iterator>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define sz size()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define CLR(x,n) memset(x,n,sizeof(x))

int n, nn;
int sudoku[102][102];

bool fill() {
	REP(i, n) REP(j, n) {
		set<int> nums;
		REP(k, nn) nums.insert(k+1);

		FOR(r, i*n, (i+1)*n) FOR(c, j*n, (j+1)*n)
			nums.erase(sudoku[r][c]);
		if ( nums.sz==1 ) {
			FOR(r, i*n, (i+1)*n) FOR(c, j*n, (j+1)*n) 
				if ( sudoku[r][c]==0 ) sudoku[r][c] = *nums.begin();
			return true;
		}
	}
	REP(i, nn) {
		set<int> nums;
		REP(k, nn) nums.insert(k+1);
		REP(k, nn) nums.erase(sudoku[i][k]);
		if ( nums.sz==1 ) {
			REP(k, nn) if ( sudoku[i][k]==0 ) sudoku[i][k] = 0;
			return true;
		}
	}
	REP(i, nn) {
		set<int> nums;
		REP(k, nn) nums.insert(k+1);
		REP(k, nn) nums.erase(sudoku[k][i]);
		if ( nums.sz==1 ) {
			REP(k, nn) if ( sudoku[k][i]==0 ) sudoku[k][i] = 0;
			return true;
		}
	}
	return false;
}

bool check() {
	bool allzero = false;
	REP(i, nn) REP(j, nn) allzero |= sudoku[i][j];
	if ( !allzero ) return true;

	REP(i, n) REP(j, n) {
		set<int> nums;
		FOR(r, i*n, (i+1)*n) FOR(c, j*n, (j+1)*n) {
			if ( sudoku[r][c] ) {
				if ( nums.find(sudoku[r][c])!=nums.end() ) 
					return false;
				nums.insert(sudoku[r][c]);
			}
		}
	}
	REP(i, nn) {
		set<int> nums;
		REP(j, nn) {
			if ( sudoku[i][j] ) {
				if ( nums.find(sudoku[i][j])!=nums.end() ) 
					return false;
				nums.insert(sudoku[i][j]);
			}
		}
	}
	REP(i, nn) {
		set<int> nums;
		REP(j, nn) {
			if ( sudoku[j][i] ) {
				if ( nums.find(sudoku[j][i])!=nums.end() ) 
					return false;
				nums.insert(sudoku[j][i]);
			}
		}
	}
	return true;
}

bool correct() {
	while ( fill() ) 
		if ( !check() ) return false;
	return check();
}

int main()
{
	scanf("%d", &n);
	nn = n*n;
	REP(i,nn) REP(j,nn) scanf("%d", &sudoku[i][j]);

	puts(correct()?"CORRECT":"INCORRECT");
	return 0;
}
