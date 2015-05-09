
#include <cstdio>
#include <cstdlib>
#include <string>

typedef struct WORD {
	char eng[11], fore[11];
} WORD;

inline int comp(const void* w1, const void* w2)
{
	return strcmp(((WORD*)w1)->fore, ((WORD*)w2)->fore);
}

int main()
{
	WORD *dic = (WORD*)malloc(sizeof(WORD)*100000);
	WORD *ptr = dic, w;
	char *eng, *fore;
	char line[32];

	while ( gets(line), strlen(line)>0 )
	{
		eng = strtok(line, " ");
		fore = strtok(NULL, " ");

		strcpy(ptr->eng, eng);
		strcpy(ptr->fore, fore);
		++ptr;
	}

	int words = ptr-dic;
	qsort(dic, words, sizeof(WORD), comp);

	while ( gets(line)!=0 )
	{
		strcpy(w.fore, line);
		ptr = (WORD*)bsearch(&w, dic, words, sizeof(WORD), comp);
		if ( ptr==NULL )
			puts("eh");
		else
			puts(ptr->eng);
	}
		
	return 0;
}
