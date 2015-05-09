#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	bool chk['Z'+1];
	bool away['Z'+1];
	while ( scanf("%d ", &n), n ) {
		memset(chk, 0, sizeof(chk));
		memset(away, 0, sizeof(away));
		int rem = n;
		int res = 0;
		char ch;
		while ( (ch=getchar())!='\n' ) {
			if ( chk[ch] ) {
				chk[ch] = 0;
				++rem;
			}
			else {
				if ( rem ) {
					chk[ch] = 1;					
					away[ch] = 0;
					--rem;
				}
				else {
					away[ch] = 1;
				}
			}
		}
		for ( int i='A' ; i<='Z' ; ++i ) if ( away[i] ) ++res;
		if ( res == 0 )
			puts("All customers tanned successfully.");			
		else
			printf("%d customer(s) walked away.\n", res);
	}
	return 0;
}


