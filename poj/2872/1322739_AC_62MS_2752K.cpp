#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LEN 12

inline int compare(const void* s1, const void* s2)
{
	return strcmp(*(char**)s1, *(char**)s2);
}

int main()
{
	int n, t;
	scanf("%d\n", &n);

	char **dic = (char**)malloc(sizeof(char*)*n);
	int i, j, correct;

	for ( i=0 ; i<n ; ++i ) {
		dic[i] = (char*)malloc(sizeof(char*)*LEN);
		gets(dic[i]);
	}

	qsort(dic, n, sizeof(char*), compare);

	char *word = (char*)malloc(LEN);
	scanf("%d\n", &t);

	for ( i=0 ; i<t ; ++i )
	{
		correct = 1;
		while ( gets(word), strcmp(word,"-1") )
		{
			if ( bsearch(&word, dic, n, sizeof(char*), compare)==NULL ) {
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