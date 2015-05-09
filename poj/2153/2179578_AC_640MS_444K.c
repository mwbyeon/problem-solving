#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#define MAX 10001

typedef struct {
	char name[32];
	int score;
} EXAM;


int name_sort(const void *s1, const void *s2)
{
	return strcmp(((EXAM*)s1)->name, ((EXAM*)s2)->name);
}

int score_sort(const void *s1, const void *s2)
{
	return *(int*)s2-*(int*)s1;
}

int main()
{
	int i, score, ming_score;
	int beg, end, mid, cmp;
	int id;
	char name[32];
	int total[MAX];
	EXAM exam[MAX];
	int n, m;

	scanf("%d\n", &n);
	memset(exam, 0x00, sizeof(exam));
	for ( i=0 ; i<n ; ++i )
		gets(exam[i].name);


	qsort(exam, n, sizeof(EXAM), name_sort);

	scanf("%d", &m);
	while ( m-- ) {
		for ( i=0 ; i<n ; ++i ) {
			scanf("%d ", &score);
			gets(name);
			for ( beg=0, end=n-1 ; beg<=end ; ) {
				mid = (beg+end)>>1;
				cmp = strcmp(name, exam[mid].name);
				if ( cmp > 0 ) 
					beg = mid+1;
				else if ( cmp < 0 ) 
					end = mid-1;
				else
					break;
			}
			total[i] = (exam[mid].score += score);
		}

		for ( beg=0, end=n-1 ; beg<=end ; ) {
			mid = (beg+end)>>1;
			cmp = strcmp("Li Ming", exam[mid].name);
			if ( cmp > 0 ) 
				beg = mid+1;
			else if ( cmp < 0 ) 
				end = mid-1;
			else
				break;
		}
		ming_score = exam[mid].score;
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