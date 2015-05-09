#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	string line;
	while ( getline(cin,line) ) {
		istringstream sin(line);
		vector<int> pt;
		int n;
		while ( sin >> n ) pt.push_back(n);
		sort(pt.begin(), pt.end());
		int sum;
		if ( (sum = accumulate(pt.begin(), pt.end(), 0)) == 0 ) break;
		sum -= *pt.begin() + *pt.rbegin();
		cout << (double)sum / (double)(pt.size()-2) << endl;
	}
	return 0;
}
