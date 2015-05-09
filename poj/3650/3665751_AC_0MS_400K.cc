#include <iostream>
using namespace std;

int main()
{
	string line;
	while ( getline(cin, line), line!="#" ) {
		int len = line.length();
		for ( int i=0 ; i<len ; ++i ) {
			switch ( line[i] ) {
				case ' ': printf("%%20"); break;
				case '!': printf("%%21"); break;
				case '$': printf("%%24"); break;
				case '%': printf("%%25"); break;
				case '(': printf("%%28"); break;
				case ')': printf("%%29"); break;
				case '*': printf("%%2a"); break;
				default : printf("%c", line[i]);
			}
		}
		puts("");
	}
	return 0;
}
