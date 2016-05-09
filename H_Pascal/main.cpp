#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)
#define ForD(i,a,b) for(int i=a; i>=b; i--)

int n,k,kt,u,v,p,t;
int a[2010][2010], l[2010];


int main()
{
   // freopen("text.inp","r",stdin);
    ios::sync_with_stdio(false);

    int n,r;
    cin>>n;
    //if (n==1) cout<<1;

    r=round(sqrt(n));
    For(i,2,r) if (n%i==0)
    {
        cout<<n-(n/i);
        return 0;
    }
    cout<<n-1;
    return 0;
}
