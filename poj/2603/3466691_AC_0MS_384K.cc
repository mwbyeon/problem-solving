#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	int res = 1;
	map<int,int> div;
	for ( int i=0 ; i<10 ; ++i ) {

		scanf("%d", &n);
		while ( n%2==0 ) {
			n /= 2;
			div[2]++;
		}
		for ( int k=3 ; n>1 ; k+=2 ) {
			while ( n%k==0 ) {
				n /= k;
				div[k]++;
			}
		}
	}

	for ( map<int,int>::iterator it=div.begin() ; it!=div.end() ; ++it ) {
		res *= it->second+1;
		res %= 10;
	}

	printf("%d\n", res);
	return 0;
}
