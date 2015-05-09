
#include <iostream>
#include <utility>
#include <algorithm>
#include <list>
using namespace std;

typedef pair<int,int>	PII;
typedef list<PII>		LPII;

inline bool firstAsc(PII s1, PII s2)
{
	return s1.first<s2.first;
}

inline bool maxSecond(PII s1, PII s2)
{
	return s1.second>s2.second;
}

inline bool part2Requi(PII s1)
{
	return s1.first < s1.second;
}

int main()
{
	int n;
	while ( cin >> n, n )
	{
		int result = 0;
		LPII work;

		for ( int i=0 ; i<n ; ++i ) {
			int s1, s2;
			cin >> s1 >> s2;
			work.push_back(make_pair(s1,s2));
		}
		work.sort(firstAsc);

		int elapse = work.begin()->first;
		int remainPart2 = work.begin()->second;
		
		work.erase(work.begin());
		
		LPII::iterator i;
		while ( !work.empty() )
		{
			i = find_if(work.begin(), work.end(), part2Requi);

			if ( i==work.end() )
				i = min_element(work.begin(), work.end(), maxSecond);

			elapse += i->first;
			if ( remainPart2 < i->first ) // if ( remainPart2-i->first<0 )
				remainPart2 = i->second;
			else			
				remainPart2 = remainPart2 - i->first + i->second;

		work.erase(i);
		}
		elapse += remainPart2;

		cout << elapse << endl;
	}
	return 0;
}
