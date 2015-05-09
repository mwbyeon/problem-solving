
#include <iostream>
#include <cstdio>
using namespace std;

typedef struct _MATRIX {
	long m[1001][1001];
	long row_sum[1001], col_sum[1001];
	int col, row;
} MATRIX;

MATRIX A, B, C;

int main()
{
	int N, P, M;
	int i, j;

	scanf("%d %d %d", &N, &P, &M);
	A.row = N;
	A.col = P;
	B.row = P;
	B.col = M;

	memset(&A, 0, sizeof(MATRIX));
	memset(&B, 0, sizeof(MATRIX));
	memset(&C, 0, sizeof(MATRIX));

	for ( i=1 ; i<=N ; ++i ) {
		for ( j=1 ; j<=P ; ++j ) {
			scanf("%d", &A.m[i][j]);
			A.col_sum[j] += A.m[i][j];
		}
	}
	for ( i=1 ; i<=P ; ++i ) {
		for ( j=1 ; j<=M ; ++j ) {
			scanf("%d", &B.m[i][j]);
			B.row_sum[i] += B.m[i][j];
		}
	}
	for ( i=1 ; i<=N ; ++i ) {
		for ( j=1 ; j<=M ; ++j ) {
			scanf("%d", &C.m[i][j]);
			C.row_sum[i] += C.m[i][j];
			C.col_sum[j] += C.m[i][j];
		}
	}

	long cval;
	int incorr_row=0, incorr_col=0;
	for ( i=1 ; i<=M ; ++i ) {
		cval = 0;
		for ( j=1 ; j<=P ; ++j )
			cval += A.col_sum[j]*B.m[j][i];
		if ( cval != C.col_sum[i] ) {
			incorr_col = i;
			break;
		}
	}	
	for ( i=1 ; i<=N ; ++i ) {
		cval = 0;
		for ( j=1 ; j<=P ; ++j )
			cval += B.row_sum[j]*A.m[i][j];
		if ( cval != C.row_sum[i] ) {
			incorr_row = i;
			break;
		}
	}

	if ( incorr_row && incorr_col ) {
		printf("No\n");
		printf("%d %d\n", incorr_row, incorr_col);

		long corr_val=0;
		for ( i=1 ; i<=P ; ++i )
			corr_val += A.m[incorr_row][i]*B.m[i][incorr_col];
		printf("%ld\n", corr_val);
	}
	else {
		printf("Yes\n");
	}
	return 0;
}

