

#include <iostream>
using namespace std;

#define MAX 100

char field[MAX+2][MAX+2];

void checkW(int x, int y);
int main()
{
	int i,j;
	int width, height,pondCnt=0;

	cin >> height >> width;

	for ( i=0 ; i<height ; i++ )
		cin >> field[i];

	for ( i=0 ; i<height ; i++ )
		for ( j=0 ; j<width ; j++ )
			if ( field[i][j] == 'W' ) {
				checkW(i,j);
				pondCnt++;
			}

	cout << pondCnt++;

	return 0;
}

void checkW(int x, int y)
{
	int i,j;
	int direct[3]={-1,0,1};

	for ( i=0 ; i<3 ; i++ )
		for ( j=0 ; j<3 ; j++ )
			if ( field[x+direct[i]][y+direct[j]] == 'W' ) {
				field[x+direct[i]][y+direct[j]] = '.';
				checkW(x+direct[i],y+direct[j]);
			}
}
