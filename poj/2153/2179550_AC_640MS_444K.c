
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[32];
	int score;
} EXAM;

EXAM exam[10001];
int n, m;

int name_sort(const void *s1, const void *s2)
{
	return strcmp(((EXAM*)s1)->name, ((EXAM*)s2)->name);
}

int score_sort(const void *s1, const void *s2)
{
	return *(int*)s2-*(int*)s1;
}

int bsearch_name(char* name)
{
	int beg, mid, end, cmp;
	for ( beg=0, end=n-1 ; beg<=end ; ) {
		mid = (beg+end)>>1;
		cmp = strcmp(name, exam[mid].name);

		if ( cmp > 0 ) 
			beg = mid+1;
		else if ( cmp < 0 ) 
			end = mid-1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int i, score, ming_score;
	int beg, end, mid;
	int id;
	char name[32];
	int total[10001];

	scanf("%d\n", &n);
	for ( i=0 ; i<n ; ++i ) {
		gets(exam[i].name);
		exam[i].score = 0;
	}

	qsort(exam, n, sizeof(EXAM), name_sort);

	scanf("%d", &m);
	while ( m-- ) {
		for ( i=0 ; i<n ; ++i ) {
			scanf("%d ", &score);
			gets(name);
			id = bsearch_name(name);
			exam[id].score += score;
			total[i] = exam[id].score;
		}
		
		ming_score = exam[bsearch_name("Li Ming")].score;
		qsort(total, n, sizeof(int), score_sort);
	
		//printf("ming score : %d\n", ming_score);
		for ( beg=0, end=n-1 ; beg<=end ; ) {
			mid = (beg+end)>>1;
			if ( total[mid] > ming_score ) 
				beg = mid+1;
			else if ( total[mid] < ming_score )
				end = mid-1;
			else
				break;
		}
		for ( ; total[mid]==total[mid-1] ; --mid);
		printf("%d\n", mid+1);
	}
	return 0;
}
