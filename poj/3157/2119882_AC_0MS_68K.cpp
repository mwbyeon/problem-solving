
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define CPP  0x1
#define JAVA 0x2

string ident_check(string& ident)
{
	int len = ident.length();
	int ver = 0;
	string result;
	string error="Error!";
	
	if ( !islower(ident[0]) ) return error;
	for ( int i=0 ; i<len ; ++i ) {
		if ( islower(ident[i]) ) {
			result += ident[i];
		}
		else {
			if ( ident[i]=='_' ) {
				if ( !islower(ident[i+1]) ) return error;
				if ( ver ) {
				   if ( ver==CPP )
					  result += toupper(ident[++i]);
				   else
					   return error;
				}
				else {
					ver = CPP;
					result += toupper(ident[++i]);
				}
			}
			else if ( isupper(ident[i]) ) {
				if ( ver ) {
					if ( ver==JAVA ) {
						result += "_";
						result += tolower(ident[i]);
					}
					else
						return error;
				}
				else {
					ver = JAVA;
					result += "_";
					result += tolower(ident[i]);
				}
			}
			else return error;
		}
	}
	return result;	
}

int main()
{
	string ident;

	getline(cin,ident);
	cout << ident_check(ident) << endl;
	return 0;
}
