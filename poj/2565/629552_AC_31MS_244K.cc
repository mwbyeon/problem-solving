
#include <iostream>
#include <cmath>
using namespace std;


int TimeToSec(const char* strTime)
{
	int hour = (strTime[0]-'0')*3600;
	int minute = (strTime[2]-'0')*600+(strTime[3]-'0')*60;
	int second = (strTime[5]-'0')*10+(strTime[6]-'0');
	
	return hour+minute+second;
}

int main()
{
	int n, team, averTime;
	double dis;
	char strTime[8];
	bool disqual;

	cin >> n >> dis;
	while ( cin >> team )
	{
		disqual = false;
		int totalSec = 0;
		for ( int i=0 ; i<n ; i++ ) {
			cin >> strTime;
			totalSec += TimeToSec(strTime);
			if ( strTime[0] == '-' )	disqual = true;
		}
		averTime = floor(totalSec/dis+0.5);
		//cout << "averTime : "<<floor(averTime+0.5)<<endl;

		if ( team<10 ) cout << " ";
		if ( team<100 ) cout << ' ';


		cout << team << ": ";
		if ( disqual )
			cout << '-' << endl;
		else {
			cout << averTime/60 << ":" ;
			if ( averTime%60 < 10 )	cout << '0';
			cout << averTime%60 << " min/km" << endl;
		}
	}
}