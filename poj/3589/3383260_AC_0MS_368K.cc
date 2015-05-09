#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	char num1[5], num2[5];
	bool chk[10];
	int a, b;
	while ( T-- ) {
		scanf("%s %s", num1, num2);

		memset(chk, 0, sizeof(chk));
		a = b = 0;
		for ( int i=0 ; i<4 ; ++i ) {
			if ( num1[i]==num2[i] ) ++a;
			else chk[num1[i]-'0'] = 1;
		}
		for ( int i=0 ; i<4 ; ++i ) {
			if ( chk[num2[i]-'0'] ) ++b;
		}
		printf("%dA%dB\n", a, b);
	}
	return 0;
}
