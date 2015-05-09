#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<long long> humbles;

void go(long long n) {
	if ( n>2000000000LL || humbles.find(n)!=humbles.end() ) return;
	humbles.insert(n);
	go(n*2LL);
	go(n*3LL);
	go(n*5LL);
	go(n*7LL);
}

int main()
{
	go(1);
	vector<int> res(humbles.begin(), humbles.end());
	
	char* suffix[] = { "th", "st", "nd", "rd" };
	int n;
	while ( scanf("%d", &n), n ) {
		if ( n%10<4 && (n%100<10 || n%100>13) ) 
			printf("The %d%s humble number is %d.\n", n, suffix[n%10], res[n-1]);
		else
			printf("The %d%s humble number is %d.\n", n, suffix[0], res[n-1]);
	}
	return 0;
}
