#include <iostream>
#include <algorithm>
using namespace std;

struct PAIR {
	int a, b, c;
};

bool operator < (const PAIR& p1, const PAIR& p2) {
	return p1.a > p2.a;
}

int main()
{
	PAIR p[50002];

	int N, K;
	scanf("%d %d", &N, &K);

	for ( int i=0 ; i<N ; ++i ) {
		scanf("%d %d", &p[i].a, &p[i].b);
		p[i].c = i+1;
	}
	sort(p, p+N);

	int maxv = -1, res = -1;
	for ( int i=0 ; i<K ; ++i ) {
		if ( p[i].b > maxv ) {
			maxv = p[i].b;
			res = p[i].c;
		}
	}
	printf("%d\n", res);

	return 0;
}
