#include <iostream>
using namespace std;

int main()
{
	bool check[100001];
	int step, mod;
	while ( scanf("%d %d", &step, &mod)!=EOF ) {
		int seed = 0;
		bool good = true;
		memset(check, 0, sizeof(check));
		check[seed] = 1;
		for ( int i=1 ; good && i<mod ; ++i ) {
			seed = (seed+step)%mod;
			if ( check[seed] ) good = false;
			check[seed] = true;
		}
		char str[64], buf[32];
		str[0] = '\0';
		sprintf(buf, "%10d", step);
		strcat(str, buf);
		sprintf(buf, "%10d", mod);
		strcat(str, buf);
		sprintf(buf, good?"    Good Choice":"    Bad Choice");
		strcat(str, buf);
		puts(str);
		puts("");
	}
	return 0;
}
