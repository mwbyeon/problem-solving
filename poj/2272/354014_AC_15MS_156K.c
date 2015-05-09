
#include <stdio.h>
#include <math.h>

typedef struct {
	double x;
	double y;
} player;

int check_point(double);

void main()
{
	int i;
	double rad_first[3],rad_second[3];
	int score_first,score_second;

	player first[3],second[3];

	first[0].x=0;
	while ( 1 )
	{
		score_first=score_second=0;

		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",
			&first[0].x,
			&first[0].y,
			&first[1].x,
			&first[1].y,
			&first[2].x,
			&first[2].y,
			&second[0].x,
			&second[0].y,
			&second[1].x,
			&second[1].y,
			&second[2].x,
			&second[2].y);
		if ( first[0].x == -100 )
			break;

		for ( i=0 ; i<3 ; i++)
		{
			rad_first[i]=sqrt(first[i].x*first[i].x + first[i].y*first[i].y);
			score_first += check_point(rad_first[i]);
			rad_second[i]=sqrt(second[i].x*second[i].x + second[i].y*second[i].y);
			score_second += check_point(rad_second[i]);
		}

	
		printf("SCORE: %d to %d, ",score_first,score_second);
		if ( score_first > score_second )
			printf("PLAYER 1 WINS.\n");
		else if ( score_first < score_second )
			printf("PLAYER 2 WINS.\n");
		else
			printf("TIE.\n");


	}
}

int check_point(double rad)
{
	if ( 0<=rad && rad<=3 )
		return 100;
	else if ( 3<rad && rad<=6 )
		return 80;
	else if ( 6<rad && rad<=9 )
		return 60;
	else if ( 9<rad && rad<=12 )
		return 40;
	else if ( 12<rad && rad<=15 )
		return 20;
	else return 0;
}