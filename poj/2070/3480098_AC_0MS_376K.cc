#include <iostream>
using namespace std;

int main()
{
	float spd;
	int wei, str;
	while ( scanf("%f %d %d", &spd, &wei, &str), spd>0.0f || wei || str ) {
		bool sol = false;
		if ( spd <= 4.5f && wei >= 150 && str >= 200 ) {
			printf("Wide Receiver ");
			sol = true;
		}
		if ( spd <= 6.0f && wei >= 300 && str >= 500 ) {
			printf("Lineman ");
			sol = true;
		}
		if ( spd <= 5.0f && wei >= 200 && str >= 300 ) {
			printf("Quarterback ");
			sol = true;
		}
		if ( !sol ) printf("No positions");
		puts("");
	}
	return 0;
}
