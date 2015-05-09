#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;

int main()
{
	primes.push_back(2); // 2는 소수
	for ( int i=3 ; i<=10000 ; i+=2 ) { // 홀수에 대해    
		int k = (int)sqrt(i);    
		bool isPrime = true;    
		for ( int j=0 ; j<primes.size() && primes[j]<=k ; ++j ) {
			if ( i%primes[j]==0 ) {
				isPrime = false;
				break;        
			}
		}
		if ( isPrime ) primes.push_back(i);
	}
	int sz = primes.size();

	int n;
	while ( scanf("%d", &n), n ) {
		int res = 0;
		for ( int i=0 ; i<sz ; ++i ) {
			int sum = primes[i];
			for ( int j=i+1 ; sum<n && j<sz ; ++j ) sum += primes[j];
			if ( sum==n ) ++res;
		}
		printf("%d\n", res);
	}
	return 0;
}



