#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	long long n, p1, p2, p3;
	cin >> p1 >> p2 >> p3 >> n;

	set<long long> ham;
	vector<long long> v;
	ham.insert(1);
	set<long long>::iterator it = ham.begin();
	while ( *it < 1000000000000000000LL ) {
		ham.insert(*it * p1);
		ham.insert(*it * p2);
		ham.insert(*it * p3);
		++it;
		v.push_back(*it);
	}
	cout << v[n-1] << endl;
	return 0;
}
