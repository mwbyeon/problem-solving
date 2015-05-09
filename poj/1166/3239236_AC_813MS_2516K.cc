#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define set_ccw(i) (ccw[(state>>(i<<1))&3]<<(i<<1))
#define set_cw(i) (cw[(state>>(i<<1))&3]<<(i<<1))
#define get(i) (state&(3<<(i<<1)))

int memo[2<<18];

int main()
{
	memset(memo, -1, sizeof(memo));
	int ccw[] = { 3, 0, 1, 2 };
	int cw[]  = { 1, 2, 3, 0 };
	bool table[][9] = {
			//A  B  C  D  E  F  G  H  I
			{ 1, 1, 0, 1, 1, 0, 0, 0, 0 },// 1
			{ 1, 1, 1, 0, 0, 0, 0, 0, 0 },// 2
			{ 0, 1, 1, 0, 1, 1, 0, 0, 0 },// 3
			{ 1, 0, 0, 1, 0, 0, 1, 0, 0 },// 4
			{ 0, 1, 0, 1, 1, 1, 0, 1, 0 },// 5
			{ 0, 0, 1, 0, 0, 1, 0, 0, 1 },// 6
			{ 0, 0, 0, 1, 1, 0, 1, 1, 0 },// 7
			{ 0, 0, 0, 0, 0, 0, 1, 1, 1 },// 8
			{ 0, 0, 0, 0, 1, 1, 0, 1, 1 } // 9
	};

	unsigned state, next;
	queue<unsigned> q;
	q.push(0);
	while ( !q.empty() ) {
		state = q.front(); q.pop();
		
		for ( int i=0 ; i<9 ; ++i ) {
			next = 0;
			for ( int j=0 ; j<9 ; ++j ) {
				if ( table[i][j] ) {
					next += set_ccw(j);
				}
				else {
					next += get(j);
				}
			}
			if ( memo[next]==-1 ) {
				q.push(next);
				memo[next] = i;
			}
		}
	}

	int c;
	state = 0;
	for ( int i=0 ; i<9 ; ++i ) {
		scanf("%d", &c);
		state += c<<(i<<1);
	}
	vector<int> trace;
	
	while ( state ) {
		trace.push_back(memo[state]);
		next = 0;
		for ( int i=0 ; i<9 ; ++i ) {
			if ( table[memo[state]][i] ) {
				next += set_cw(i);
			}
			else {
				next += get(i);
			}
		}
		state = next;
	}

	for ( int i=trace.size()-1 ; i>=0 ; --i ) printf("%d ", trace[i]+1);
	
	return 0;
}


