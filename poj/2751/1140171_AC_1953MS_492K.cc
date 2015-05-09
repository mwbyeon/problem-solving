
#include <iostream>
#include <utility>
#include <algorithm>
#include <list>
using namespace std;

typedef pair<int,int>	PII;
typedef list<PII>		LPII;

// first가 작은 순서.. second가 큰 순서;
inline bool firstAsc(PII s1, PII s2)
{
	if ( s1.first==s2.first )
		return s1.second>s2.second;
	return s1.first<s2.first;
}

inline bool maxSecond(PII s1, PII s2)
{
	if ( s1.second == s2.second )
		return s1.first<s1.first;
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

		// Find First Work (First Ascending, Second Descending)
		// first가 작은 순서대로 정렬; 같을경우 second가 큰 순서;
		work.sort(firstAsc);

		int elapse = work.begin()->first;
		int remainPart2 = work.begin()->second;
		
		work.erase(work.begin());
		
		LPII::iterator i;
		while ( !work.empty() )
		{
			// first가 작은 순서대로 정렬되어 있는데... 다음 remainPart가 지금보다 작으면 
			// 다음 차례에 시간을 더 낭비하게 될 것이므로 안됨;
			// for ( i=work.begin() ; i->second >= i->first && i<work.end() ; ++i );
				//if ( remainPart2 <= remainPart2 - i->first + i->second ) break;

			i = find_if(work.begin(), work.end(), part2Requi);

			if ( i==work.end() )
				i = min_element(work.begin(), work.end(), maxSecond);

			elapse += i->first;
			if ( remainPart2 < i->first ) // if ( remainPart2-i->first<0 )
				remainPart2 = i->second;
			else			
				remainPart2 = remainPart2 - i->first + i->second;

//			cout <<  i->first << ' ' << i->second << "\t";
//			cout << elapse << ' ' << remainPart2 << endl;

			work.erase(i);
		}
		elapse += remainPart2;

		cout << elapse << endl;
	}
	return 0;
}
