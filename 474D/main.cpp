#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)
#define ForD(i,a,b) for(int i=a; i>=b; i--)
#define rep(i,a) For(i,0,int(a.size())-1)
#define repD(i,a) ForD(i,int(a.size())-1,0)
#define fi first
#define se second
#define pb push_back
#define reset(a,x) memset(a,x,sizeof(a))
#define N 100010
#define base 1000000007

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int f[N], x,y,t,k;

int main()
{
  //  freopen("text.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin>>t>>k;
    f[0]=1;
    For(i,1,100000)
    {
        f[i]=f[i-1];
        if (i>=k) f[i]+=f[i-k];
        f[i]%=base;
    }
    For(i,1,100000) f[i]=(f[i-1]+f[i])%base;

    For(i,1,t)
    {
        cin>>x>>y;
        cout<<(f[y]+base-f[x-1])%base<<"\n";
    }
    return 0;



    return 0;
}
