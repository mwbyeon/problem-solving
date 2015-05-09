#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d ", &T);

	char buf[2][15];
	while ( T-- ) {
		int a, b;
		scanf("%d %d", &a, &b);
		sprintf(buf[0], "%d", a);
		sprintf(buf[1], "%d", b);
		reverse(buf[0], buf[0]+strlen(buf[0]));
		reverse(buf[1], buf[1]+strlen(buf[1]));
		a = atoi(buf[0]);
		b = atoi(buf[1]);
		sprintf(buf[0], "%d", a+b);
		reverse(buf[0], buf[0]+strlen(buf[0]));
		printf("%d\n", atoi(buf[0]));
	}
	return 0;
}
