

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> VS;

int main()
{
	int n;
	int i, j, len;
	int alpha[32], tmp[32], result;
	string str;

	while ( cin >> n , n ) 
	{
		VS dic;
		dic.reserve(n);
		for ( i=0 ; i<n ; ++i ) {
			cin >> str;
			dic.push_back(str);
		}
		
		cin >> str;
		len = str.length();
		memset(alpha, 0, sizeof(alpha));
		for ( i=0 ; i<len ; ++i )
			alpha[str[i]-'A']++;

		result = 0;
		for ( i=0 ; i<n ; ++i ) {
			memcpy(tmp, alpha, sizeof(tmp));
			str = dic[i];
			len = str.length();
			for ( j=0 ; j<len ; ++j ) {
				if ( tmp[str[j]-'A'] )
					tmp[str[j]-'A']--;
				else
					if ( tmp['_'-'A'] )
						tmp['_'-'A']--;
					else
						break;
			}

			if ( j==len )
				result++;
		}
		cout << result << endl;
	}
	return 0;
}

					
					
		
			
