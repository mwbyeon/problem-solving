#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef struct vitamin {
	float a, r, p;
	string u, v;
} vitamin;

int main()
{
	vitamin vt;
	vector<vitamin> good, bad;

	while ( cin >> vt.a >> vt.u >> vt.r, vt.a>=0 )
	{
		cin.ignore(1, ' ');
		getline(cin, vt.v);

		for ( int i=vt.v.length()-1 ; vt.v[i]==' ' ; --i )
			vt.v.erase(i);


		vt.p = vt.a/vt.r*100;
		if ( vt.p < 1 )
			bad.push_back(vt);
		else
			good.push_back(vt);
	}
	vector<vitamin>::iterator i;
	for ( i=good.begin() ; i<good.end() ; ++i )
		printf("%s %.1f %s %.f%%\n", i->v.c_str(), i->a, i->u.c_str(), i->p);
	if ( !bad.empty() ) {
		cout << "Provides no significant amount of:" << endl;
		for ( i=bad.begin() ; i<bad.end() ; ++i )
			cout << i->v << endl;
	}
	return 0;
}


