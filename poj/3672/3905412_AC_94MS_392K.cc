#include <iostream>
using namespace std;

int main()
{
	int M, T, U, F, D;
	scanf("%d %d %d %d %d ", &M, &T, &U, &F, &D);

	int res = 0;
	bool flag = true;
	char path;
	while ( T-- ) {
		scanf("%c ", &path);
		if ( path == 'f' ) {
			M -= F+F;
		}
		else {
			M -= U+D;
		}
		if ( M < 0 ) flag = false;
		if ( flag ) ++res;
	}

	printf("%d", res);
	return 0;
}
