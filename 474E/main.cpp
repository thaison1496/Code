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
#define N 100100

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

pair<ll,int> b[N];
ll a[N];
int s[4*N], l[4*N], h[4*N], leaf[N], f[N], tr[N], r[N], p[N];

int n,rs,d,k;

int mx(int i, int j)
{
    if (f[i]==f[j])
    {
        if (i==0) return i;
        if (j==0) return j;
    }
    if (f[i]<f[j]) return j; else return i;
}

int build(int x, int i, int j)
{
    l[x]=i; h[x]=j;
    if (i==j)
    {
        s[x]=b[i].se;
        leaf[i]=x;
        return 0;
    }
    build(x*2,i,(i+j)/2);
    build(x*2+1,(i+j)/2+1,j);
    s[x]=0;
    return 0;
}

int get(int x, ll v)
{
    if (b[l[x]].fi>=v+d) return s[x];
    if (b[h[x]].fi<=v-d) return s[x];
    if (v-d<b[l[x]].fi && b[h[x]].fi<v+d) return 0;
    return mx(get(x*2,v),get(x*2+1,v));
    return 0;
}

int update(int i)
{
    int x=leaf[i];
    while (x>1)
    {
        x/=2;
        s[x]=mx(s[x*2],s[x*2+1]);
    }
    return 0;

}
int main()
{
    //freopen("text.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n>>d;
    For(i,1,n)
    {
        cin>>b[i].fi;
        a[i]=b[i].fi;
        b[i].se=i;
    }
//n=100; d=0;
//For(i,1,n) {a[i]=5000000000; b[i].fi=a[i]; b[i].se=i;}
    sort(b+1,b+n+1);
    For(i,1,n) p[b[i].se]=i;

    build(1,1,n);

    reset(f,0);
    reset(tr,0);
    For(i,1,n)
    {
       // cout<<f[i]<<endl;
        tr[i]=get(1,a[i]);
        if (f[tr[i]]==0) tr[i]=0;
        f[i]=f[tr[i]]+1;
        update(p[i]);
    }

    rs=1;
    For(i,2,n) if (f[i]>f[rs]) rs=i;
    k=0;
    cout<<f[rs]<<"\n";
    while (rs!=0)
    {
        r[++k]=rs;
        rs=tr[rs];
    }


    ForD(i,k,1) cout<<r[i]<<" ";


    return 0;
}
