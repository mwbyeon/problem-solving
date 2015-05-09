#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LEN 10

inline int compare(const void* s1, const void* s2)
{
	return strcmp(*(char**)s1, *(char**)s2);
}

int main()
{
	int n, t;
	scanf("%d\n", &n);

	char **dic = (char**)malloc(4*n);
	int i, j, correct;

	for ( i=0 ; i<n ; ++i ) {
		dic[i] = (char*)malloc(4*LEN);
		gets(dic[i]);
	}

	qsort(dic, n, 4, compare);

	char *word = (char*)malloc(LEN);
	scanf("%d\n", &t);

	for ( i=0 ; i<t ; ++i )
	{
		correct = 1;
		while ( 1 )
		{
			gets(word);
			if ( word[0]=='-' ) break;
			if ( bsearch(&word, dic, n, 4, compare)==NULL ) {
				if ( correct ) {
					printf("Email %d is not spelled correctly.\n", i+1);
					correct=0;
				}
				puts(word);
			}
		}
		if ( correct )
			printf("Email %d is spelled correctly.\n", i+1);
	}
	puts("End of Output");
	return 0;
}

