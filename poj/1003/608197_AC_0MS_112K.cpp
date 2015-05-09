
#include <iostream>
using namespace std;

int main()
{
	float len;
	while ( cin >> len , len )
	{
		float hang = 0;
		for ( int i=2 ; hang < len ; ++i)
			hang += (float)1/(float)i;

		cout << i-2 <<" card(s)" << endl;
	}
}