
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
	int i, score;
	int beg, end, mid;
	string name;
	MSI exam;
	VI total;
	total.reserve(10001);

	cin >> n;
	cin.ignore(1);
	for ( i=0 ; i<n ; ++i ) {
		getline(cin, name, '\n');
		exam.insert(make_pair(name,0));
	}
	
	cin >> m;
	while ( m-- ) {
		for ( i=0 ; i<n ; ++i ) {
			cin >> score;
			cin.ignore(1);
			getline(cin, name, '\n');
			exam[name] += score;
			total.push_back(exam[name]);
		}
		sort(total.begin(), total.end(), greater<int>());
		//copy(total.begin(), total.end(), ostream_iterator<int>(cout," "));

		beg=0, end=n-1;
		while ( beg<=end ) {
			mid = (beg+end)/2;
			if ( total[mid]>exam["Li Ming"] ) 
				beg = mid+1;
			else if ( total[mid]<exam["Li Ming"] ) 
				end = mid-1;
			else
				break;		
		}
		for ( ; total[mid]==total[mid-1] ; mid-- );
		cout << mid+1 << endl;
		total.clear();
	}
	return 0;
}
