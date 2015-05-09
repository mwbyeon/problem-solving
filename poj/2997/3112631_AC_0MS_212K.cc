#include <cstdio>
#include <cstring>

char line[10001];
int res, len, curr;

int go5(char rom, int num) {
	for ( int i=curr ; i<len ; ++i ) if ( line[i]==rom ) {
		res += num;
		curr = i+1;
		return true;
	}
	return false;
}

bool go4(char rom1, char rom2, int num) {
	for ( int i=curr ; i<len ; ++i ) if ( line[i]==rom1 ) {
		for ( int j=i+1 ; j<len ; ++j ) if ( line[j]==rom2 ) {
			res += num;
			curr = j+1;
			return true;
		}
		return false;
	}
	return false;
}

bool go1(char rom, int num) {
	int cnt = 0;
	for ( int i=curr ; i<len ; ++i ) if ( line[i]==rom ) {
		res += num;
		curr = i+1;
		if ( ++cnt == 3 ) return true;
	}
	return cnt;
}


int main()
{

	while ( gets(line), line[0]!='\0' ) {
		len = strlen(line);

		res = curr = 0;

		for ( int i=curr ; i<len ; ++i ) if ( line[i]=='m' ) {
			res += 1000;
			curr = i+1;
		}

		if ( !go5('d', 500) ) go4('c', 'd', 400);
		go1('c', 100);

		if ( !go4('x','c',90) ) {
			if ( !go5('l',50) ) go4('x','l',40);
			go1('x', 10);
		}

		if ( !go4('i','x',9) ) {
			if ( !go5('v',5) ) go4('i','v',4);
			go1('i', 1);
		}

		printf("%d\n", res);
		line[0] = '\0';
	}
	return 0;
}
