#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#define min(x,y) x<y?x:y

int min_distance(string& s) {
	int i, res=99;
	for ( i=1 ; i<s.length() ; ++i )
		res = min(res, abs(s[i]-s[i-1]));
	return res;
}

int main()
{
	string name;
	while ( cin >> name ) {
		int i, res_mdst=min_distance(name), dst;
		string res_pmt(name), tmp(name);

		for ( i=0 ; i<10 ; ++i ) {
			prev_permutation(tmp.begin(), tmp.end());
			dst = min_distance(tmp);
			//cout << tmp << ' ' << dst <<  endl;
			if ( dst >= res_mdst ) {
				res_mdst = dst;
				res_pmt = tmp;
			}
			next_permutation(name.begin(), name.end());
			dst = min_distance(name);
			//cout << name << ' ' << dst << endl;
			if ( dst > res_mdst ) {
				res_mdst = dst;
				res_pmt = name;
			}
		}
		cout << res_pmt << res_mdst << endl;
	}
	return 0;
}
