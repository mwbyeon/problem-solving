
#include <iostream>
#include <cstring>
using namespace std;

int M, N;
int matrix[18][305];
int row[18];
int selected[18];
bool check[18][18][305];
int count[305];

bool solve()
{
	memset(check, 1, sizeof(check));
	for ( int i=0 ; i<M ; ++i )
	{
		for ( int j=0 ; j<M ; ++j )
		{
			for ( int k=0 ; k<N ; ++k )
			{
				if ( matrix[i][k] + matrix[j][k] == 2 )
				{
					check[i][j][k] = check[j][i][k] = false;
				}
			}
		}
	}

	int k = 1 << M;
	for ( int mask=1 ; mask<k ; ++mask )
	{
		int cnt = 0;
		bool res = true;
		int sum = 0;
		for ( int i=0 ; i<M ; ++i )
		{
			if ( (mask&(1<<i)) > 0 )
			{
				selected[cnt++] = i;
				sum += row[i];
				if ( sum > N )
				{
					res = false;
					break;
				}
			}
		}
		if ( !res || sum != N ) continue;

		for ( int i=0 ; i<cnt ; ++i )
		{
			for ( int j=0 ; j<cnt ; ++j )
			{
				if ( !check[i][j] ) 
				{
					res = false;
					break;
				}
			}
		}
		if ( !res ) continue;

		
		memset(count, 0, sizeof(count));
		for ( int i=0 ; i<cnt ; ++i )
		{
			for ( int j=0 ; j<N ; ++j )
			{
				count[j] += matrix[selected[i]][j];
				if ( count[j] > 1 )
				{
					res = false;
					break;
				}
			}
			if ( !res ) break;
		}

		if ( res )
		{
			return true;
		}
	}
	return false;
}

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	while ( scanf("%d %d", &M, &N) == 2)
	{
		memset(row, 0, sizeof(row));
		for ( int i=0 ; i<M ; ++i )
		{
			for ( int j=0 ; j<N ; ++j )
			{
				scanf("%d", &matrix[i][j]);
				row[i] += matrix[i][j];
			}
		}
		puts(solve()?"Yes, I found it":"It is impossible");
	}
	return 0;
}
