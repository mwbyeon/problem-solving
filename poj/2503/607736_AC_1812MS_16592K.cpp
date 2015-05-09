
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string,string > dic;
	string frg,eng;

	while ( 1 ) {
		if(cin.peek()=='\n') break;

		cin >> eng >> frg ;
		cin.ignore();
		dic[frg]=eng;
	}
	while ( cin >> frg ) {
		map<string,string>::iterator value = dic.find(frg);
		if ( value != dic.end() )
			cout << value->second << endl;
		else
			cout << "eh" << endl;
	}
}