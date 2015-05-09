

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string,int> PIECE;
typedef vector<PIECE> VPIECE;
typedef vector<int> VI;

int main()
{
	int nColors, nClothes;

	while ( cin >> nColors >> nClothes, nColors && nClothes ) {
		int i, j;
		VPIECE piece(nClothes);
		string color;

		for ( i=0 ; i<nColors ; ++i )
			cin >> color;

		for ( i=0 ; i<nClothes ; ++i )
			cin >> piece[i].second >> piece[i].first;

		sort(piece.begin(), piece.end());

		int totalTime = 0;
		for ( i=0 ; i<nClothes ; ) {
			int timeSum = 0, maxTime=0;
			VI time(100000, 0);
			j=i;
			for ( color=piece[i].first ; i<nClothes && color==piece[i].first ; ++i )
				timeSum += piece[i].second;
			for ( ; j<i ; ++j ) {
				for ( int k=timeSum/2 ; k>=piece[j].second ; --k ) {
					time[k] = max(time[k], time[k-piece[j].second]+piece[j].second);
					maxTime = max(maxTime, time[k]);
				}
			}
			totalTime += max(maxTime, timeSum-maxTime);
		}
		cout << totalTime << endl;
	}
	return 0;
}
