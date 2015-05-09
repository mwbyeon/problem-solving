
#include <stdio.h>
#include <string.h>

int main()
{
	char command[7];
	char address[101][70]={"http://www.acm.org/"};

	int location=0;

	scanf("%s",command);
	while ( strcmp(command,"QUIT") )
	{
		if ( !strcmp(command,"VISIT") ) {
			scanf("%s",address[++location]);
			puts(address[location]);
			address[location+1][0] = '\0';
		}
		else if ( !strcmp(command,"BACK") ) {
			if ( location == 0 )
				puts("Ignored");
			else
				puts(address[--location]);
		}
		else if ( !strcmp(command,"FORWARD") ) {
			if ( address[location+1][0] == '\0' )
				puts("Ignored");
			else
				puts(address[++location]);
		}
		scanf("%s",command);
	}

	return 0;
}