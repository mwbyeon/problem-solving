
#include <iostream>
using namespace std;

int main()
{
	int nine[10];
	int tmp;
	char n[10], *c;
	int res, i, digit, len;

	tmp = 1;
	for ( i=0 ; i<10 ; ++i ) {
		nine[i] = tmp;
		tmp *= 9;
	}


	while ( cin >> n, *n!='0' )
	{
		cout << n << ": ";
		c = n;
		for ( len=0, c=n ; *c ; ++c, ++len )
			if ( *c>'4' )
				(*c) -= 1;
		i=0;
		res = 0;
		for ( --c ; c!=n ; --c ) {
			digit = (*c)-'0';
			res += nine[i++]*digit;
		}
		digit = *(c)-'0';
		res += nine[i]*digit;
		cout << res << endl;
	}
}
