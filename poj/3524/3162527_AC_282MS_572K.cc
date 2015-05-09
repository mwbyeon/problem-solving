
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

struct Array {
	int size;
	map<int,int> value;
};

Array array[128];
vector<string> prog;

bool validRange(char name, int idx) {
	return idx!=-1 && idx<array[name].size && array[name].size!=-1;
}

int getValue(string expr) {
	if ( expr.find_first_not_of("0123456789")!=expr.npos ) { // expr
		int val = getValue(expr.substr(2, expr.length()-3));
		if ( !validRange(expr[0], val) || array[expr[0]].value.find(val)==array[expr[0]].value.end() ) return -1;
		return array[expr[0]].value[val];
	}
	else {	// num
		return atoi(expr.c_str());
	}
	return -1;
}

int findBug() {
	int n = prog.size();
	for ( int i=0 ; i<n ; ++i ) {
		string& line(prog[i]);
		int pos = line.find("=");
		if ( pos==line.npos ) { // declar
			array[line[0]].size = atoi(line.substr(2, line.length()-3).c_str());
		}
		else {
			string lhs = line.substr(0, pos);
			string rhs = line.substr(pos+1);
			int lidx = getValue(lhs.substr(2, lhs.length()-3));
			int ridx = getValue(rhs);
			if ( lidx == -1 || ridx == -1 || !validRange(lhs[0], lidx) ) return i+1;
			array[lhs[0]].value[lidx] = ridx;
		}
	}
	return 0;
}

int main()
{
	string line;
	while ( getline(cin, line), line[0]!='.' ) {
		prog.clear();
		for ( int i=0 ; i<128 ; ++i ) {
			array[i].size = -1;
			array[i].value.clear();
		}

		do prog.push_back(line); while ( getline(cin, line), line[0]!='.' );
		printf("%d\n", findBug());
	}

	return 0;
}
