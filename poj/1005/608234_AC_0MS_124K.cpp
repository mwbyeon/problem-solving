
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for ( int i=1 ; i<=t ; i++ )
	{
		int year = 1;
		double x, y;
		cin >> x >> y;
		while ( 1 ) {
			double dis = sqrt(pow(x,2)+pow(y,2));
			double land = sqrt(year*50*2/3.1415926535);
			if ( dis<=land ) break;
			++year;
		}
		cout << "Property "<< i << ": This property will begin eroding in year " << year << '.' << endl;
	}
	cout << "END OF OUTPUT." << endl;
}