#include <iostream>
using namespace std;

#define MAX 1000000000

int main()
{
       long num, a, b, c, result, sum, half, remain, i;
       cin >> num;
       while(num--)
       {
               sum = 0;
               cin >> a >> b;
               c = b - a;
               half = c/2;

               for(i=0; i<MAX; i++)
               {
                       sum += i;
                       if(sum > half)
                               break;
               }
               result = (i - 1) * 2;
               sum -= i;
               remain = c - sum * 2;
               if(remain != 0)
               {
                       if(remain > i)
                               result += 2;
                       else
                               result += 1;
               }
               cout << result << endl;
       }
}
