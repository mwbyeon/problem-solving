
#include <stdio.h>
#include <memory.h>

enum { WIN, TOTAL };

int main()
{
	int n, k, p1, p2, i, len1, len2;
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

			// 스트링 길이를 구하고 가위바위보 결정;
			for ( t1=s1 ; *t1 ; ++t1 );
			len1 = t1-s1;
			switch ( len1 ) {
				case 8: len1=1; break;	// scissors
				case 4:	len1=2; break;	// rock
				case 5:	len1=4; break;	// paper
				default: break;
			}
			for ( t2=s2 ; *t2 ; ++t2 );
			len2 = t2-s2;
			switch ( len2 ) {
				case 8: len2=1; break;
				case 4: len2=2; break;
				case 5: len2=4; break;
				default: break;
			}

			// 가위, 보 일 경우;
			if ( (len1|len2)==5 ) {
				table[len1<len2?p1:p2][WIN]++;
				table[p1][TOTAL]++;
				table[p2][TOTAL]++;
			}
			// 무승부가 아닐 경우; 큰 숫자가 이김;
			else if ( len1^len2 ) {
				table[len1>len2?p1:p2][WIN]++;
				table[p1][TOTAL]++;
				table[p2][TOTAL]++;
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
