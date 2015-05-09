#include <iostream>
using namespace std;

int main()
{
 int n;
 while(cin>>n) {
 int v=1,c=1;
 while(v) {
  v=(v*10+1)%n;
  c++;
 }
 cout<<c<<endl;
 }
}
