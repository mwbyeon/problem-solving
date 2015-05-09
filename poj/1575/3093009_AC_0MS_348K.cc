#include <iostream>
#include <cstdio>
using namespace std;

const string vowels("aeiou");

inline bool isvowel(const char ch) {
	return vowels.find(ch)!=string::npos;
}

bool acceptable(string& word) {
	if ( word.find_first_of(vowels)==string::npos ) return false;
	int len = word.size();
	int cnt = 1;
	for ( int i=1 ; i<len ; ++i ) {
		if ( word[i]==word[i-1] && word[i]!='e' && word[i]!='o' ) return false;
		if ( isvowel(word[i]) != isvowel(word[i-1]) ) cnt = 1; 
		else ++cnt;
		if ( cnt > 2) return false;
	}
	return true;
}

int main()
{

	string word;
	while ( cin >> word, word!="end" ) {
		printf("<%s> is %sacceptable.\n", word.c_str(), acceptable(word)?"":"not ");
	}
	return 0;
}
