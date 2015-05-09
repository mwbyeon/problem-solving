#include <iostream>
using namespace std;

int main()
{
	string line;
	int hh, mm, ss, spd, sec1 = 0, sec2 = 0;
	double dist = 0.0;
	double msec = 0.0;
	while ( getline(cin, line), isdigit(line[0]) ) {
		spd = -1;
		sscanf(line.c_str(), "%d:%d:%d %d", &hh, &mm, &ss, &spd);
		sec2 = hh*3600 + mm*60 + ss;

		if ( spd < 0 ) {
			dist += (sec2-sec1)*msec;
			printf("%s %.2lf km\n", line.c_str(), dist);
		}
		else {
			dist += (sec2-sec1)*msec;
			msec = spd/3600.0;
		}
		sec1 = sec2;
	}
	return 0;
}
