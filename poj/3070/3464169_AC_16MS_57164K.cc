#include <iostream>
using namespace std;

#define MOD 10000

int fibo[150010];
int fc = 0; 
int chk[10000][10000] = {0,};
int beg;

void go(int a, int b) {
	if ( chk[a][b] ) {
		beg = chk[a][b];
		return ;
	}
	chk[a][b] = fc;
	fibo[fc++] = b;
	go(b, (a+b)%MOD);
}

int main()
{
	fibo[fc++] = 0;
	go(0,1);
	int n;

	while ( scanf("%d", &n), n>=0 ) {
		printf("%d\n", fibo[n%(fc-1)]);
	}
	return 0;
}
