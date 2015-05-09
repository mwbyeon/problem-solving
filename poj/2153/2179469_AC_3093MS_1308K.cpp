
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

typedef map<string,int> MSI;
typedef vector<int> VI;

int main()
{
	int n, m;
	int i, score, ming_score;
	int beg, end, mid;
	string name;
	MSI exam;
	int total[10001];

	cin >> n;
	cin.ignore(1);
	for ( i=0 ; i<n ; ++i ) {
		getline(cin, name, '\n');
		exam.insert(make_pair(name,0));
	}
	
	cin >> m;
	while ( m-- ) {
		for ( i=0 ; i<n ; ++i ) {
			scanf("%d", &score);
			//cin >> score;
			cin.ignore(1);
			getline(cin, name, '\n');
			exam[name] += score;
			total[i] = exam[name];
		}
		sort(total, total+n, greater<int>());

		beg=0, end=n-1;
		ming_score = exam["Li Ming"];
		while ( beg<=end ) {
			mid = (beg+end)>>1;
			if ( total[mid]>ming_score ) 
				beg = mid+1;
			else if ( total[mid]<ming_score ) 
				end = mid-1;
			else
				break;		
		}
		for ( ; total[mid]==total[mid-1] ; mid-- );
		cout << mid+1 << endl;
	}
	return 0;
}
