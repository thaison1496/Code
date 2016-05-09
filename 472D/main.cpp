#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)
#define ForD(i,a,b) for(int i=a; i>=b; i--)

int n,k,kt,u,v,p,t;
int a[2010][2010], l[2010];


int no()
{
    cout<<"NO";
    exit(0);
}

int ck(int k, int j)
{
    u=l[j];
    For(i,0,k)
    {
        p=l[i];
        if (a[p][u]+a[u][v]!=a[p][v]) return 0;
    }
    kt=u;
    return 0;
}

bool cmp(int i, int j)
{
    return (a[1][i]<a[1][j]);
}
int main()
{
    //freopen("text.inp","r",stdin);
    ios::sync_with_stdio(false);

    cin>>n;
    int n1=n-1; int n2=n-2;
    For(i,1,n)
    For(j,1,n) cin>>a[i][j];

    For(i,1,n) if (a[i][i]!=0) no();

    For(i,1,n1)
    For(j,i+1,n)
    {
        if (a[i][j]==0) no();
        if (a[i][j]!=a[j][i]) no();
    }

    For(i,2,n) l[i-1]=i;

    sort(l+1,l+n,cmp);

    l[0]=1;
    int ii;
    For(i,1,n1)
    {
        v=l[i];
        kt=-1;
        t=0;
        For(j,1,i-1) if (a[l[j]][v]<a[l[t]][v]) t=j;

        ck(i-1,t);
        if (kt==-1) no();
    }
    cout<<"YES";
    return 0;
}
