
#include <iostream>
#include <cstdio>
using namespace std;

char map[302][302];
int mine[302][302];
int sz, mines;

void init()
{
	memset(map, 0, sizeof(map));
	memset(mine, 0, sizeof(mine));
}

void input()
{
	cin >> sz >> mines;
	sz++;

	int m_x, m_y;
	for ( int i=0 ; i<mines ; ++i ) {
		cin >> m_x >> m_y;
		map[m_x][m_y] = '*';
		mine[m_x-1][m_y]++;
		mine[m_x+1][m_y]++;
		mine[m_x][m_y-1]++;
		mine[m_x][m_y+1]++;
		mine[m_x-1][m_y-1]++;
		mine[m_x-1][m_y+1]++;
		mine[m_x+1][m_y-1]++;
		mine[m_x+1][m_y+1]++;
	}
}

void create_map(int x, int y)
{
	if ( x==0 || x==sz || y==0 || y==sz || map[x][y])
		return;

	if ( mine[x][y] ) {
		map[x][y] = '#';
		return;
	}
	map[x][y] = '.';
	create_map(x-1, y);
	create_map(x+1, y);
	create_map(x, y-1);
	create_map(x, y+1);
	create_map(x-1, y-1);
	create_map(x-1, y+1);
	create_map(x+1, y-1);
	create_map(x+1, y+1);
}		

void process()
{
	create_map(sz/2, sz/2);
}

void output(int t)
{
	printf("Scenario #%d:\n", t);
	for ( int i=1 ; i<sz ; ++i ) {
		for ( int j=1 ; j<sz ; ++j ) {
			if ( map[i][j] )
				printf("%c",map[i][j]);
			else
				printf("?");
		}
		puts("");
	}
	puts("");
}

int main()
{
	int T, t;
	for ( cin>>T, t=0 ; t<T ; ++t )
	{
		init();
		input();
		process();
		output(t+1);
	}
	return 0;
}
