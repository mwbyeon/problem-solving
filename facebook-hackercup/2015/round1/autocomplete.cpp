
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    //freopen("autocomplete_example_input.txt", "r", stdin);

    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        int N;
        cin >> N;

        set<string> dict;
        int res = 0;
        for ( int i=0 ; i<N ; ++i ) {
            string word;
            cin >> word;

            int press = word.length();
            string sub = "";
            for ( int j=0 ; j<word.length() ; ++j ) {
                sub += word[j];
                if ( dict.find(sub) == dict.end() ) {
                    press = j + 1;
                    break;
                }
            }
            //cout << word << ' '<< press << endl;

            sub = "";
            for ( int j=0 ; j<min(128, (int)word.length()) ; ++j ) {
                sub += word[j];
                dict.insert(sub);
            }
            res += press;
        }
        printf("Case #%d: %d\n", tc, res);
    }
    return 0;
}