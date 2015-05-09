#include <string>
#include <iostream>
using namespace std;

char mirror[128];

int palindrome(string& str) {
	int len = str.length();
	
	int palin = 1, mirr = 2;
	for ( int i=0 ; i<(len+1)/2 ; ++i ) {
		if ( str[i]!=str[len-1-i] ) palin = 0;
		if ( str[i]!=mirror[str[len-1-i]] ) mirr = 0;
	}
	return palin + mirr;
}

int main()
{
	memset(mirror, 0, sizeof(mirror));
	mirror['A'] = 'A';
	mirror['E'] = '3'; mirror['3'] = 'E';
	mirror['H'] = 'H';
	mirror['I'] = 'I';
	mirror['J'] = 'L'; mirror['L'] = 'J';
	mirror['M'] = 'M';
	mirror['O'] = 'O';
	mirror['S'] = '2'; mirror['2'] = 'S';
	mirror['T'] = 'T';
	mirror['U'] = 'U';
	mirror['V'] = 'V';
	mirror['W'] = 'W';
	mirror['X'] = 'X';
	mirror['Y'] = 'Y';
	mirror['Z'] = '5'; mirror['5'] = 'Z';
	mirror['1'] = '1';
	mirror['8'] = '8';

	//printf("%d %d %d %d\n", 'A', 'Z', '1', '9');
	string str;
	while ( cin >> str ) {
		printf("%s", str.c_str());
		switch ( palindrome(str) ) {
			case 0: puts(" -- is not a palindrome."); break;
			case 1: puts(" -- is a regular palindrome."); break;
			case 2: puts(" -- is a mirrored string."); break;
			case 3: puts(" -- is a mirrored palindrome."); break;
		}
		puts("");
	}
	return 0;
}
