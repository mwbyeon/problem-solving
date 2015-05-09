#include <stdio.h>
#include <string.h>

void main()
{
	char c[7];
	char a[101][70]={"http://www.acm.org/"};

	int l=0;

	scanf("%s",c);
	while ( strcmp(c,"QUIT") )
	{
		if ( !strcmp(c,"VISIT") ) {
			scanf("%s",a[++l]);
			puts(a[l]);
			a[l+1][0] = '\0';
		}
		else if ( !strcmp(c,"BACK") ) {
			if ( l == 0 )
				puts("Ignored");
			else
				puts(a[--l]);
		}
		else if ( !strcmp(c,"FORWARD") ) {
			if ( a[l+1][0] == '\0' )
				puts("Ignored");
			else
				puts(a[++l]);
		}
		scanf("%s",c);
	}
}
