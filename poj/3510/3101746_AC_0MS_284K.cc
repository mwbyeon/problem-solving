// critical data : Fei  iei eie

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	char line[82];
	int p;
	while ( gets(line) ) {
		int len = strlen(line);

		for ( int i=0 ; i<len ; ) {
			if ( line[i]=='E' && line[i+1]=='O' && line[i+2]=='F' ) {
				return 0;
			}
			else if ( line[i]=='d' && line[i+1]=='d' ) {
				printf("p");
				i +=2 ;
			}
			else if ( line[i]=='p' && line[i+1]=='i' && line[i+2]=='n' && line[i+3]=='k' ) {
				printf("floyd");
				i += 4;
			}
			else if ( line[i]=='e' && line[i+1]=='i' ) {
				if ( i==0 ) {
					printf("ie");
					i += 2;
				}
				else if ( line[i-1]!='c' ) {
					printf("ie");
					i += 2;
				}
				else {
					printf("ei");
					i += 2;
				}
			}
			else if ( islower(line[i]) || line[i]==' ' ) {
				putchar(line[i]);
				i += 1;
			}
			else ++i;
		}
		puts("");
	}
	return 0;
}


