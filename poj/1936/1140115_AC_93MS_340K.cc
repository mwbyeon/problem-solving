
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    while ( cin >> s1 >> s2 )
    {
        int i, j=0;
        for ( i=0 ; i<s2.length() ; ++i )
            if ( s1[j]==s2[i] ) j++;
        if ( j==s1.length() )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
