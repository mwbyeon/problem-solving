
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, p, i, j;

	cin >> n >> p;
	vector<int> rank(p), output;
	vector<pair<int,int> > problem(p);

	for ( i=0 ; i<n ; i++ ) {
		for ( j=0 ; j<p ; j++ )	cin >> rank[j];

		vector<int>::iterator min = min_element(rank.begin(), rank.end());
		vector<int>::iterator max = max_element(rank.begin(), rank.end());
		for ( j=0; j<p ; j++ ) {
			if ( rank[j] == *min ) problem[j].first++;
			if ( rank[j] == *max ) problem[j].second++;
		}
	}

	for ( i=0 ; i<n ; i++ )
		if ( problem[i].first>n/2 && problem[i].second==0 )
			output.push_back(i+1);
	
	if ( output.size()==0 )
		printf("0");
	else
		for ( i=0 ; i<(signed)output.size() ; i++ )
			printf("%d ",output[i]);
	printf("\n");
}