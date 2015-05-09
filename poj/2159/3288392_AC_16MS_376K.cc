#include <iostream>
using namespace std;

int main()
{
	char str1[101], str2[101];
	int v1[27]={0,}, v2[27]={0,};
	scanf("%s %s", str1, str2);

	int l1 = strlen(str1);
	int l2 = strlen(str2);

	for ( int i=0 ; i<l1 ; ++i ) v1[str1[i]-'A']++;
	for ( int i=0 ; i<l2 ; ++i ) v2[str2[i]-'A']++;

	sort(v1, v1+26);
	sort(v2, v2+26);

	for ( int i=0 ; i<26 ; ++i ) if ( v1[i]!=v2[i] ) {
		puts("NO");
		return 0;
	}
	puts("YES");

	return 0;
}
