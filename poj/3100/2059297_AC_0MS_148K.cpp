
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, n;
	while ( cin >> b >> n, b && n ) {
		if ( n-1<0.0001 ) {
			cout << (int)b << endl;
		}
		else {
			a = floor(pow(b,1/n));
			cout << (fabs(b-pow(a,n))<fabs(b-pow(a+1,n))?a:a+1) << endl;
		}
	}
	return 0;
}
