#include <iostream>
using namespace std;

int main ()
{
       int s1, s2, s3;
       while (cin >> s1 >> s2 >> s3) {
               int A, B, C;
               C = s1;
               A = (s1 + s3 - 2 * s2 ) / 2;
               B = s2 - s1 - A;
               cout    << 9*A + 3*B + C  << " "
                       << 16*A + 4*B + C << " "
                       << 25*A + 5*B + C << endl;
       }
       return 0;
}
