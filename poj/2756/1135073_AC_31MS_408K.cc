
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

#define MAX		50*1024
#define PLUS	'+'
#define MINUS	'-'

typedef struct BigNum {
	char sign;
	string digits;
	int length;
} BigNum;

string addition(string, string);
string subtraction(string, string);
void calculate(BigNum&, BigNum&, BigNum&);
inline void toDigit(char&);
inline void toChar(char&);

int main()
{
	int tCase;
	
	for ( cin >> tCase ; tCase-- ; )
	{
		BigNum bn1, bn2, result;

		cin >> bn1.digits >> bn2.digits;

		if ( isdigit(bn1.digits[0]) )
			bn1.sign = PLUS;
		else {
			bn1.sign = bn1.digits[0];
			bn1.digits = bn1.digits.substr(1, bn1.digits.length()-1);
		}
		if ( isdigit(bn2.digits[0]) )
			bn2.sign = PLUS;
		else {
			bn2.sign = bn2.digits[0];
			bn2.digits = bn2.digits.substr(1, bn2.digits.length()-1);
		}
		for_each(bn1.digits.begin(), bn1.digits.end(), toDigit);
		for_each(bn2.digits.begin(), bn2.digits.end(), toDigit);
		bn1.length = bn1.digits.length();
		bn2.length = bn2.digits.length();

		calculate(bn1, bn2, result);
		
		for_each(result.digits.begin(), result.digits.end(), toChar);

		if ( result.digits[0]==0 )
			cout << "0" << endl;
		else {
			if ( result.sign=='-')
				cout << '-';
			cout << result.digits << endl;
		}
	}
	return 0;
}

inline void toDigit(char& c) {
	c -= '0';
}

inline void toChar(char& c) {
	c += '0';
}

void calculate(BigNum& bn1, BigNum& bn2, BigNum& result)
{
	if ( bn1.sign == bn2.sign ) {
		result.sign = bn1.sign;
		result.digits = addition(bn1.digits, bn2.digits);
		result.length = result.digits.length();
	}
	else {
		if ( bn1.length > bn2.length ) {
			result.sign = bn1.sign==MINUS ? MINUS : PLUS;
			result.digits = subtraction(bn1.digits, bn2.digits);
		}
		else if ( bn1.length < bn2.length ) {
			result.sign = bn1.sign==MINUS ? PLUS : MINUS;
			result.digits = subtraction(bn2.digits, bn1.digits);
		}
		else {
			int i;
			for ( i=0 ; bn1.digits[i]==bn2.digits[i] && i<bn1.length ; ++i );
			if ( bn1.digits[i] > bn2.digits[i] ) {
				result.sign = bn1.sign==MINUS ? MINUS : PLUS;
				result.digits = subtraction(bn1.digits, bn2.digits);
			}
			else {
				result.sign = bn1.sign==MINUS ? PLUS : MINUS;
				result.digits = subtraction(bn2.digits, bn1.digits);
			}
		}
	}
}

string addition(string s1, string s2) 
{
	char carry = 0;
	int len = max(s1.length(), s2.length());
	
	string zero(MAX, 0);
	string result(len, 0);

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	s1.append(zero, 0, len-s1.length());
	s2.append(zero, 0, len-s2.length());	//0을 덧붙임;

	int i;
	for ( i=0 ; i<len ; ++i ) {
		result[i] = s1[i]+s2[i]+carry;
		carry = 0;
		if ( result[i]>9 ) {
			carry = 1;
			result[i] -= 10;
		}
	}
	if ( carry==1 )	result += 1;
	
	reverse(result.begin(), result.end());
	for ( i=0 ; result[i]==0 && i<result.length() ; ++i);

	result = result.substr(i, result.length()-i);

	return result;
}

string subtraction(string s1, string s2)
{
	int i;
	int len = s1.length();
	
	string zero(MAX, 0);
	string result(len, 0);

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	s2.append(zero, 0, len-s2.length());	//0을 덧붙임;

	for ( i=0 ; i<len ; ++i ) {
		if ( s1[i]-s2[i]<0 ) {
			result[i] = 10+s1[i]-s2[i];
			--s1[i+1];
		}
		else {
			result[i] = s1[i]-s2[i];
		}
	}

	reverse(result.begin(), result.end());
	for ( i=0 ; result[i]==0 && i<result.length() ; ++i );

	result = result.substr(i, result.length()-i);

	return result;
}

