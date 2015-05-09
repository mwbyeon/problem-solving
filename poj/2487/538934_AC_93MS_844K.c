#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

void main()
{
    int t, i, scenario;
    int stamps, stamp_sum;
    int friends, *friends_stamp;

    for ( scanf("%d",&t), scenario=1 ; t ; t--, scenario++ )
    {
        scanf("%d %d",&stamps, &friends);
        friends_stamp = (int*)malloc(sizeof(int)*friends);
        for ( i=0 ; i<friends ; i++ )
            scanf("%d",&friends_stamp[i]);

        qsort(friends_stamp,friends,sizeof(int),cmp);

        stamp_sum = 0;
        for ( i=0 ; stamp_sum < stamps && i<friends ; i++ )
            stamp_sum += friends_stamp[i];

        if ( stamp_sum >= stamps )
            printf("Scenario #%d:\n%d\n\n",scenario, i);
        else 
            printf("Scenario #%d:\nimpossible\n\n",scenario);
    }
    free(friends_stamp);
}