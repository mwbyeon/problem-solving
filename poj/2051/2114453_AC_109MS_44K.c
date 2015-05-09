
#include <stdio.h>
#include <stdlib.h>

#define MAX 3001

typedef struct _QUERY {
	int num;
	int period;
	int temp;
} QUERY;

int cmp(const void* a, const void* b) {
	if ( ((QUERY*)a)->temp==((QUERY*)b)->temp ) 
		return ((QUERY*)a)->num - ((QUERY*)b)->num;
	return ((QUERY*)a)->temp - ((QUERY*)b)->temp;
}

int main()
{
	int num, period, count;
	char reg[10];
	int q_num, i, j;

	QUERY query[MAX], tmpq;

	for ( q_num=0 ; scanf("%s", reg), *reg!='#' ; ++q_num ) {
		scanf("%d%d", &num, &period);
		query[q_num].num = num;
		query[q_num].period = query[q_num].temp = period;
	}
	qsort(query, q_num, sizeof(QUERY), cmp);

	scanf("%d", &count);
	while ( count-- ) {
		printf("%d\n", query[0].num);
		for ( i=1 ; i<q_num ; ++i ) 
			query[i].temp -= query[0].temp;
		query[0].temp = query[0].period;

		// sort;
		tmpq = query[0];
		for ( i=1 ; i<q_num && tmpq.temp>query[i].temp ; ++i )
			query[i-1] = query[i];
		for ( j=i ; j<q_num && tmpq.temp==query[j].temp && tmpq.num>query[j].num ; ++j )
			query[j-1] = query[j];
		query[j-1] = tmpq;
	}
	return 0;
}
