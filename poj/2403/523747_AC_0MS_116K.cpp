
#include <iostream>
using namespace std;

int main()
{
	int w, d;
	int i;
	char word[1000][17], desc[17];
	int *point, totalPoint;

	cin >> w >> d;

	point = (int*)malloc(sizeof(int)*w);

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
	free(point);
	return 0;
}