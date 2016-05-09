#include <iostream>
#include <fstream>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)

int main()
{
    int n;
    cin>>n;
    if (n%2==0) cout<<8<<" "<<n-8; else cout<<9<<" "<<n-9;
    return 0;
}
