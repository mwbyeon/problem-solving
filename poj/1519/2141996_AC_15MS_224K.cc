
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string itoa(int num) {
	string buf;
	for ( int i=30 ; num && i ; --i ) {
		buf = "0123456789"[num%10]+buf;
		num /= 10;
	}
	return buf;
}

int single_digit(string line)
{
	int res, sum=0;
	for ( int i=0 ; i<line.length() ; ++i ) 
		sum += line[i]-'0';
	if ( sum>9 ) 
		return single_digit(itoa(sum));
	return sum;
}

int main()
{
	string line;
	
	while ( cin >> line, line!="0")
		cout << single_digit(line) << endl;
	return 0;
}
	
