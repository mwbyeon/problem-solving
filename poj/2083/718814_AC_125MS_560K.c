#include <stdio.h>
#include <math.h>

#define SIZE 730

char fractal[SIZE][SIZE];

void draw_fractal(int n, int x, int y) {
    int pos = pow(3,n-2), i;

    if ( n==1 ) {
        fractal[x][y] = 'X';
        return;
    }

    draw_fractal(n-1, x, y);
    draw_fractal(n-1, x-pos, y-pos);
    draw_fractal(n-1, x-pos, y+pos);
    draw_fractal(n-1, x+pos, y-pos);
    draw_fractal(n-1, x+pos, y+pos);
}

int main()
{
    int size, i, j, pos;
    while ( scanf("%d",&size), size != -1 )
    {
        for ( i=0 ; i<pow(3,size-1) ; i++ )
            for ( j=0 ; j<pow(3,size-1) ; j++ )
                fractal[i][j] = ' ';

        pos = pow(3,size-1);
        draw_fractal(size, pos/2, pos/2);

        for ( i=0 ; i<pos ; i++ ) {
            for ( j=0 ; j<pos ; j++ )
                printf("%c",fractal[i][j]);
            printf("\n");
        }
        printf("-\n");
    }
}

