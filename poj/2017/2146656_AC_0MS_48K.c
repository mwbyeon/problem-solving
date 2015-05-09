void main()
{
	int n, s, t, prev, dist;
	while ( scanf("%d", &n), n>0 ) {
		prev = dist = 0;
		while ( n-- ) {
			scanf("%d %d", &s, &t);
			dist += (t-prev)*s;
			prev = t;
		}
		printf("%d miles\n", dist);
	}
}
