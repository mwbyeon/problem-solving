
#include <stdio.h>
#include <string.h>

int main()
{
	int t, sum, len, s=1, i;
	char id[8], fact[3], qpos;

	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%s",id);

		len = (int)strlen(id);
		for ( i=0 ; i<len ; i++ ) {
			if ( id[i]!='?' )
				id[i] = id[i]-'0';
			else {
				id[i] = 0;
				qpos = i;
			}
		}
		if ( len==6 ) {
			fact[0]=7; 
			fact[1]=3;
			fact[2]=9;
		}
		if ( len==7 ) {
			fact[0]=9;
			fact[1]=7;
			fact[2]=3;
		}


		sum = 0;
		for ( i=0 ; i<len ; i++ )
			sum += id[i]*fact[i%3];

		for ( i=9 ; (i*fact[qpos%3]+sum)%10 ; i-- );

		id[qpos] = i;

		printf("Scenario #%d:\n",s++);
		for ( i=0 ; i<len ; i++ )
			printf("%d",id[i]);
		printf("\n\n");
	}
	return 0;
}
