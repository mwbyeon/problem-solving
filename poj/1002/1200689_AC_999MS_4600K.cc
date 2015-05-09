
#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

#define BUFF 40

int main()
{
	char *mapping = "22233344455566677778889999";	// Q:7 Z:9
	char *pn = new char[BUFF], *t;
	char *newpn = new char[10], *u;
	string npn;
	map<string, int> list;
	
	int n;
	scanf("%d ", &n);
	do {
		scanf("%s", pn);
		t = pn;
		u = newpn;

		do {
			if ( *t!='-' ) {
				if ( '0'<=*t && *t<='9' )
					*u++ = *t;
				else if ( *t!='Q' || *t!='Z' )
					*u++ = mapping[*t-'A'];
			}
		} while ( *++t );
		*u = 0;

		npn = newpn;
		list[npn]++;
	} while ( --n );

	bool dup = false;
	map<string, int>::iterator i=list.begin();
	do {
		if ( i->second != 1 ) {
			printf("%c%c%c-%c%c%c%c %d\n", 
					i->first[0], i->first[1], i->first[2],
					i->first[3], i->first[4], i->first[5], i->first[6],
					i->second);
			dup = true;
		}
		++i;
	} while ( i!=list.end() );

	if ( !dup )	cout << "No duplicates."<< endl;
	return 0;
}
