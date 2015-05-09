#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int target;
	string num;

	while ( cin >> target >> num, target ) {
		int len = num.length()-1;
		int maxv = -1, ans = 0;
		vector< pair<int,int> > candi;

		for ( int m=0 ; m<(1<<len) ; ++m ) {
			int sum = 0;
			int mask = m | 1<<len;
			for ( int i=0, k=0 ; i<=len ; ++i ) {
				if ( mask & (1<<i) ) {
					sum += atoi(num.substr(k,i-k+1).c_str());
					k = i+1;
				}
			}
			if ( sum <= target ) candi.push_back(make_pair(sum, mask));
		}
		sort(candi.rbegin(), candi.rend());

		if ( candi.empty() ) {
			puts("error");
		}
		else if ( candi.size()>1 && candi[0].first == candi[1].first ) {
			puts("rejected");
		}
		else {
			printf("%d ", candi[0].first);
			ans = candi[0].second;
			for ( int i=0, k=0 ; i<=len ; ++i ) {
				if ( ans & (1<<i) ) {
					cout << num.substr(k,i-k+1) << ' ';
					k = i+1;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
