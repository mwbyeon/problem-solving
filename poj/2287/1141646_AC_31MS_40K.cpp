#include <stdio.h>
#include <algorithm>
using namespace std;

int n,s;
int a[2000],b[2000],c[2000],nc,na;

int main() {
	int i,j,mi,mj;
	while (scanf("%d",&n)!=EOF) {
		if (!n) return 0;
		for (i=0; i<n; ++i) scanf("%d",&a[i]);
		for (i=0; i<n; ++i) scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		i=0; j=0; mi=0; s=0; nc=0; mj=0;
		while (j<n && i<n) {
			while (i<n && j<n && b[j]<a[i]) {
				if (nc==0 || c[nc-1]!=b[j]) {
					++j; s+=200;  ++mj;
				} else {
					while (j<n && b[j]==c[nc-1]) ++j;
					if (j==n || b[j]<a[i]) {
						b[j]=c[nc-1];
						j=++mj; s+=200;
					} else {
						j=++mj; s+=200;
					}
				}
				++i;
			}
			if (i<n) {
				c[nc++]=a[i];
			}
			++i;
		}
		i=nc-1; mi=0;
		while (i>=0 && j<n) {
			if (c[i]==b[j]) { --i; ++j; ++mi; }
			else break;
		}
		s-=200*(nc-mi);
		printf("%d\n",s);
	}
	return 0;
}

