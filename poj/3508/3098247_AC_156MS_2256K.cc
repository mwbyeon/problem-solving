#include <iostream>
#include <string>
using namespace std;

char num[1000001];
char res[1000001];
int len;

bool solve() {
	res[len-1] = num[len-1];
	for ( int i=len-2 ; i>=0 ; --i ) {
		if ( num[i] < '0' ) {
			num[i-1] -= 1;
			num[i] += 10;
		}
		int t = num[i]-res[i+1];
		if ( t < 0 ) {
			t = 10+t;
			num[i-1] -= 1;
		}
		res[i] += t;
	}
	if ( res[0]<'1' ) return false;
	return true;
}

int main()
{
	for ( int T=1 ; scanf("%s", num), num[0]!='0' ; ++T ) {
		len = strlen(num);
		memset(res, '0', sizeof(char)*len);
		res[len] = '\0';

		if ( solve() ) 
			printf("%d. %s\n", T, res);
		else
			printf("%d. IMPOSSIBLE\n", T);
	}
	return 0;
}
