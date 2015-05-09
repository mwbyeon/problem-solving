

#include <stdio.h>
#include <string.h>

void main()
{
	char str[80];
	char comm[11];
	int i;
	
	gets(comm);
	while ( strcmp(comm,"ENDOFINPUT") )
	{
		gets(str);
		while ( strcmp(str,"END") )
		{
			for ( i=0 ; i<(int)strlen(str) ; i++ ) {
				if ( 'F'<=str[i] && str[i]<='Z' )
					str[i] -= 5;
				else if ( 'A'<=str[i] && str[i]<='E')
					str[i] += 21;
			}
			puts(str);
			gets(str);
		}
		gets(comm);
	}
}