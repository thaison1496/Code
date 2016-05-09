#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)
#define ForD(i,a,b) for(int i=a; i>=b; i--)

int k,t,r;
int a[10100];
int main()
{
  //  freopen("text.inp","r",stdin);
    int n;
    cin>>n>>k;
    For(i,1,n) cin>>a[i];
    For(i,1,n) a[i]--;
    sort(a+1,a+n+1);
    //if (k>n) {cout<<a[n]*2; return 0;}
    t=k;
    ForD(i,n,1)
    {
        t--;
        if (t==0) {r+=2*a[i+k-1]; t=k;}
    }
    if (t!=k) r+=2*a[k-t];
    cout<<r;
    return 0;
}
