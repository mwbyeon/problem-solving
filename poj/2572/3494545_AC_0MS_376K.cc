#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char line[32];
	int a, b, c, len;
	while ( scanf("%s", line), strcmp(line, "0+0=0") ) {
		len = strlen(line);
		reverse(line, line+len);
		sscanf(line, "%d = %d + %d", &c, &b, &a);
		puts(a+b==c?"True":"False");
	}
	puts("True");
	return 0;
}
