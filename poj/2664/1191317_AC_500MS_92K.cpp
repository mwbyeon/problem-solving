
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int k, m, c, r, cnt, i, j ;
	string s;
	set<string>::iterator find;
	bool possible;
	
	
	while ( cin >> k >> m, k && m ) 
	{
		possible = true;
		set<string> course;
		for ( i=0 ; i<k ; ++i ) {
			cin >> s;
			course.insert(s);
		}
		
		for ( i=0 ; i<m ; ++i ) {
			cin >> c >> r;
			for ( cnt=j=0 ; j<c ; ++j ) {
				cin >> s;
				if ( possible && course.find(s)!=course.end() )
					cnt++;
			}
			if ( cnt < r ) possible = false;
		}

		if ( possible ) 
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
		
		
