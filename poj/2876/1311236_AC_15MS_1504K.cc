
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

inline int power(int n, int m)
{
	return pow((double)n,(double)m);
}

int main()
{
	// 3^12 = 531441
	string cantor = "-";
	cantor.reserve(power(3,12));
	string space(power(3,11), ' ');

	int t=12;
	while ( t-- )
	{
		int len = cantor.length();
		cantor += space.substr(0, len);
		cantor += cantor.substr(0, len);
	}
	
	int n;
	while ( cin >> n )
		cout << cantor.substr(0, power(3,n) ) << endl;
	
	return 0;
}

