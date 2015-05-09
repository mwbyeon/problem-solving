#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <vector>
using namespace std;

typedef __int64 LL;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

bool cmp(PII a, PII b) {
	return 1.*a.first/(a.second*2) < 1.*b.first/(b.second*2);
}

int main()
{
	int N, i;
	cin >> N;

	VPII cows; cows.reserve(N);
	int ds = 0;

	for ( i=0 ; i<N ; ++i ) {
		int a, b;
		scanf("%d %d", &a, &b);
		ds += b;
		cows.push_back(make_pair(a,b));
	}
	sort(cows.begin(), cows.end(), cmp);

	LL res = 0;
	for ( i=0 ; i<N ; ++i ) {
		ds -= cows[i].second;
		res += (ds*cows[i].first*2);
	}
	//cout << res;
printf("%I64d", res);
	return 0;
}
