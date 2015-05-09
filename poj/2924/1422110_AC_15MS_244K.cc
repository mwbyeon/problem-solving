
#include <iostream>
using namespace std;

inline __int64 sigma(__int64 n)
{
	return (n*n+n)>>1;
}

int main()
{
	__int64 a, b, sum;
	int T, t;
	for ( cin >> T, t=0 ; t<T ; ++t ) 
	{
		cin >> a >> b;

		if ( a<0 ) 
			if ( b<0 ) 
				sum = -sigma(-a)+sigma(b);
			else
				sum = -sigma(-a)+sigma(b);
		else
			sum = sigma(b)-sigma(a-1);
		
		cout << "Scenario #" << t+1 << ":\n"
			 << sum << "\n\n";
	}
	return 0;
}
