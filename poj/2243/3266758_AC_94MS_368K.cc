
#include <iostream>
#include <queue>
using namespace std;

inline bool valid(int i, int j) { return i>=0 && j>=0 && i<8 && j<8; }

int main()
{
	char k1[4], k2[4];
	bool chess[8][8];
	int di[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
	int dj[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
	
	while ( scanf("%s %s", k1, k2)!=EOF ) {
		printf("To get from %s to %s takes ", k1, k2);
		k1[0] -= 'a';
		k1[1] -= '1';
		k2[0] -= 'a';
		k2[1] -= '1';
		memset(chess, 0, sizeof(chess));
		queue<int> q;
		q.push((k1[0]<<4)+(k1[1]));
		int top, ii, jj;
		while ( !q.empty() ) {
			top = q.front(); q.pop();
			if ( ((top>>4)&0xF)==k2[0] && (top&0xF)==k2[1] ) break;
			
			for ( int k=0 ; k<8 ; ++k ) {
				ii = ((top>>4)&0xF)+di[k];
				jj = (top&0xF)+dj[k];
				if ( valid(ii, jj) && !chess[ii][jj] ) {
					chess[ii][jj] = 1;
					q.push( ((((top>>8)&0xFF)+1)<<8)|(ii<<4)|jj);
				}
			}
		}
		printf("%d knight moves.\n", (top>>0x8)&0xFF);  
	}
	return 0;
}