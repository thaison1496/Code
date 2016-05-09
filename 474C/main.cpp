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
#define sqr(x) (x)*(x)

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;


int d[25][5], a[5];
bool av[5];
pii p[5], f[5], r[5], g[5];
int n,ct;

pii creat(int i, int k)
{
    int x=p[i].fi-r[i].fi;
    int y=p[i].se-r[i].se;
    int t;
    while (k--)
    {
        t=x;
        x=-y;
        y=t;
    }
    return make_pair(x+r[i].fi,y+r[i].se);
}

ll ds(int i, int j)
{
    return sqr(g[i].fi-g[j].fi)+sqr(g[i].se-g[j].se);
}
int ck(int ii)
{
    For(i,1,4) g[i]=f[d[ii][i]];
    return (ds(1,2)>0 && ds(1,3)>0 && ds(1,2)==ds(2,3) && ds(2,3)==ds(3,4) && ds(3,4)==ds(4,1) && ds(1,3)==ds(2,4) );
}
int xuly()
{
    int r=100;
    For(i,0,3)
    For(j,0,3)
    For(k,0,3)
    For(t,0,3)
    {
        if (i+j+k+t>=r) continue;
        f[1]=creat(1,i);
        f[2]=creat(2,j);
        f[3]=creat(3,k);
        f[4]=creat(4,t);
        For(ii,1,24) if (ck(ii)) r=i+j+k+t; //cout<<i<<j<<k<<t;}
    }
    if (r<100) cout<<r<<"\n"; else cout<<-1<<"\n";
    return 0;
}

int fin(int i)
{
    if (i==5)
    {
        ct++; For(j,1,4) d[ct][j]=a[j];
        return 0;
    }
    For(j,1,4) if (av[j])
    {
        a[i]=j;
        av[j]=false;
        fin(i+1);
        av[j]=true;
    }
    return 0;
}
int main()
{
    //freopen("text.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;

    ct=0; reset(av,true);
    fin(1);

    For(i,1,n)
    {
        For(j,1,4) cin>>p[j].fi>>p[j].se>>r[j].fi>>r[j].se;
        xuly();
    }
    return 0;



    return 0;
}
