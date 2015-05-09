
#include <iostream>
#include <cstdio>
using namespace std;

int getTimes(char ch)
{
	switch ( ch ) {
		case ' ':
		case 'A':	
		case 'D':
		case 'G':
		case 'J':
		case 'M':
		case 'P':
		case 'T':
		case 'W':
			return 1;
		case 'B':
		case 'E':
		case 'H':
		case 'K':
		case 'N':
		case 'Q':
		case 'U':
		case 'X':
			return 2;
		case 'C':
		case 'F':
		case 'I':
		case 'L':
		case 'O':
		case 'R':
		case 'V':
		case 'Y':
			return 3;
		case 'S':
		case 'Z':
			return 4;
	}
}

int getKey(char ch)
{
	switch ( ch ) {
		case ' ':
			return 1;
		case 'A':
		case 'B':
		case 'C':
			return 2;
		case 'D':
		case 'E':
		case 'F':
			return 3;
		case 'G':
		case 'H':
		case 'I':
			return 4;
		case 'J':
		case 'K':
		case 'L':
			return 5;
		case 'M':
		case 'N':
		case 'O':
			return 6;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			return 7;
		case 'T':
		case 'U':
		case 'V':
			return 8;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			return 9;
	}
}

int main()
{
	char str[1001];
	int tc;
	int pressTime, fixedTime, totalTime;
	int len;

	cin >> tc;
	while ( tc-- )
	{
		cin >> pressTime >> fixedTime;
		cin.ignore(1);
		gets(str);
		len = (int)strlen(str);
		//cout << str << endl;

		totalTime = getTimes(str[0])*pressTime;
		for ( int i=1 ; i<len ; ++i ) {
			if ( str[i]!=' ' && getKey(str[i])==getKey(str[i-1]) )
				totalTime += fixedTime;
			totalTime += getTimes(str[i])*pressTime;
			
		}
		cout << totalTime << endl;
					
		
	}
	return 0;
}
