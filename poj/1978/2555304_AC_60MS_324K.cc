#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, r;
	while ( cin >> n >> r, n && r ) {
		vector<int> cards(n);
		for ( int i=0 ; i<n ; ++i ) cards[i] = n-i;
		while ( r-- ) {
			int p, c;
			cin >> p >> c;
			vector<int> cut(cards.begin()+p-1, cards.begin()+p-1+c);
			cards.erase(cards.begin()+p-1, cards.begin()+p-1+c);
			cards.insert(cards.begin(), cut.begin(), cut.end());
		}
		cout << cards[0] << endl;
	}
	return 0;
}
