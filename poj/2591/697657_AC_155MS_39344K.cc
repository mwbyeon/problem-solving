#include <iostream>
using namespace std;

#define MAX 10000000

unsigned long seq[MAX];

int main()
{
unsigned long idx=0, two=0, three=0, tmp1, tmp2;
seq[0]=1;

 for ( idx=1 ; idx<MAX ; ++idx ) {
tmp1 = (seq[two]<<1)+1;
tmp2 = (seq[three]<<1)+seq[three]+1;

if ( tmp1<tmp2 ) {
seq[idx] = tmp1;
++two;
 }
else if ( tmp1>tmp2 ) {
seq[idx] = tmp2;
++three;
}
 else {
seq[idx] = tmp1;
++two;
++three;
}
}

while ( cin >> idx )
cout << seq[idx-1] << endl;
}
