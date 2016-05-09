#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)
#define ForD(i,a,b) for(int i=a; i>=b; i--)

int m,n,p,k,q;
int d[110100];
string s, a[10100], b[10100];
char c;
int chk(int x, int y)
{
    c=s[x];
    s[x]=s[y];
    s[y]=c;
    m=n/2;

    For(i,0,m) if (s[i]!=s[n-i])
    {
        c=s[x];
        s[x]=s[y];
        s[y]=c;
        return 0;
    }
    a[++k]=s;
    c=s[x];
    s[x]=s[y];
    s[y]=c;

    return 0;
}
int main()
{
   // freopen("text.inp","r",stdin);
    ios::sync_with_stdio(false);


    getline(cin,s);
    n=s.size()-1;
    if (n==0)
    {
        cout<<0;
        return 0;
    }

    q=0;
    For(i,0,n/2) if (s[i]!=s[n-i]) {d[++q]=i; d[++q]=n-i;}
    if (q>8) {cout<<0; return 0;}
    if (q==0) {cout<<1<<"\n"; cout<<s; return 0;}
    k=0;
    For(i,1,q-1)
    For(j,i+1,q)
        chk(d[i],d[j]);

    if (k==0)
    {
        cout<<0;
        return 0;
    }
    sort(a+1,a+k+1);
    p=1;
    b[1]=a[1];
    For(i,2,k)
        if (a[i]!=a[i-1]) b[++p]=a[i];
    cout<<p<<"\n";
    For(i,1,p) cout<<b[i]<<"\n";

    return 0;
}
