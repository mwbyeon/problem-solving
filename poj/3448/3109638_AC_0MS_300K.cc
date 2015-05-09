#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int reg[10];
	memset(reg, -1, sizeof(reg));

	char line[10002];
	bool err;
	while ( gets(line) ) {
		err = false;
		if ( line[0]=='Q' ) {
			puts("Bye");
			return 0;
		}
		else if ( line[0]=='R' ) {
			memset(reg, -1, sizeof(reg));
			puts("Ready");
		}
		else {
			int len = strlen(line);
			int res = 0;
			int sign = 1;
			for ( int i=2 ; i<len ; ) {
				if ( line[i]=='I' ) {
					if ( line[i+1]=='V' ) {
						res += 4*sign;
						i += 2;
					}
					else if ( line[i+1]=='X' ) {
						res += 9*sign;
						i += 2;
					}
					else {
						res += 1*sign;
						i += 1;
					}
				}
				else if ( line[i]=='X' ) {
					if ( line[i+1]=='L' ) {
						res += 40*sign;
						i += 2;
					}
					else if ( line[i+1]=='C' ) {
						res += 90*sign;
						i += 2;
					}
					else {
						res += 10*sign;
						i += 1;
					}
				}
				else if ( line[i]=='C' ) {
					if ( line[i+1]=='D' ) {
						res += 400*sign;
						i += 2;
					}
					else if ( line[i+1]=='M' ) {
						res += 900*sign;
						i += 2;
					}
					else {
						res += 100*sign;
						i += 1;
					}
				}
				else if ( line[i]=='O' ) {
					res += 0;
					i += 1;
				}
				else if ( line[i]=='V' ) {
					res += 5*sign;
					i += 1;
				}
				else if ( line[i]=='L' ) {
					res += 50*sign;
					i += 1;
				}
				else if ( line[i]=='D' ) {
					res += 500*sign;
					i += 1;
				}
				else if ( line[i]=='M' ) {
					res += 1000*sign;
					i += 1;
				}
				else if ( line[i]=='+' ) {
					sign = 1;
					i += 1;
				}
				else if ( line[i]=='-' ) {
					sign = -1;
					i += 1;
				}
				else if ( isdigit(line[i]) ) {
					if ( reg[line[i]-'0']==-1 ) {
						err = true;
						break;
					}
					else {
						res += reg[line[i]-'0']*sign;
						i += 1;
					}
				}
				else puts("WHAT'S IT?");
			}
			if ( err || res < 0 || res > 10000 ) {
				puts("Error");
			}
			else {
				reg[line[0]-'0'] = res;
				printf("%c=", line[0]);
				if ( res == 0 ) printf("O");
				while ( res >= 1000 ) {
					printf("M");
					res -= 1000;
				}
				if ( res >= 900 ) {
					printf("CM");
					res -= 900;
				}
				if ( res >= 500 ) {
					printf("D");
					res -= 500;
				}
				if ( res >= 400 ) {
					printf("CD");
					res -= 400;
				}
				while ( res >= 100 ) {
					printf("C");
					res -= 100;
				}
				if ( res >= 90 ) {
					printf("XC");
					res -= 90;
				}
				if ( res >= 50 ) {
					printf("L");
					res -= 50;
				}
				if ( res >= 40 ) {
					printf("XL");
					res -= 40;
				}
				while ( res >= 10 ) {
					printf("X");
					res -= 10;
				}
				if ( res >= 9 ) {
					printf("IX");
					res -= 9;
				}
				if ( res >= 5 ) {
					printf("V");
					res -= 5;
				}
				if ( res >= 4 ) {
					printf("IV");
					res -= 4;
				}
				while ( res >= 1 ) {
					printf("I");
					res -= 1;
				}
				puts("");
			}
		}
	}
	return 0;
}
