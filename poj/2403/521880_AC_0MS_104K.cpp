
#include <iostream>
using namespace std;

int main()
{
	int w, d;
	int i;
	char word[1001][20], desc[20];
	long point[1001], totalPoint;

	cin >> w >> d;

	for ( i=0 ; i<w ; i++ )
		cin >> word[i] >> point[i];
	
	while ( d-- ) 
	{
		totalPoint = 0;
		cin >> desc;
		while ( strcmp(desc,".") )
		{
			for ( i=0 ; i<w ; i++ )
				if ( !strcmp(desc,word[i]) )
					totalPoint += point[i];
			cin >> desc;
		}
		cout << totalPoint << endl;
	}
	return 0;
}