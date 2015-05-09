
#include <stdio.h>
#include <memory.h>

enum { WIN, TOTAL };

int main()
{
	int n, k, p1, p2, i, len1, len2, player1, player2;
	long total, table[102][2];
	char s1[16], s2[16], *t1, *t2;
	float res;

	// 가위바위보 테이블;
	memset(table, 0, sizeof(table));

	while ( scanf("%d %d", &n, &k)==2 )
	{
		// many input;
		total = k;
		total *= n;
		total *= n-1;
		total >>= 1;

		while ( total-- ) 
		{
			scanf("%d %s %d %s", &p1, s1, &p2, s2);

			// 가위(1)바위(2)보(4) 결정;
			switch ( *s1 ) {
				case 's': player1=1; break;
				case 'r': player1=2; break;
				case 'p': player1=4; break;
			}
			switch ( *s2 ) {
				case 's': player2=1; break;
				case 'r': player2=2; break;
				case 'p': player2=4; break;
			}

			// 가위, 보 일 경우;
			if ( (player1|player2)==5 ) {
				++table[player1<player2?p1:p2][WIN];
				++table[p1][TOTAL];
				++table[p2][TOTAL];
			}
			// 무승부가 아닐 경우; 큰 숫자가 이김;
			else if ( player1^player2 ) {
				++table[player1>player2?p1:p2][WIN];
				++table[p1][TOTAL];
				++table[p2][TOTAL];
			}
		}

		// 승률 출력;
		for ( i=1 ; i<=n ; ++i ) {
			if ( table[i][TOTAL] ) {
				res = (float)table[i][WIN]/(float)table[i][TOTAL];
				printf("%.3f\n", res);
			}
			else
				puts("-");
			// 테이블 초기화;
			table[i][WIN]=table[i][TOTAL]=0;
		}
		puts("");// '\n'
	}
	return 0;
}

