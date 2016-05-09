#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)
#define ForD(i,a,b) for(int i=a; i>=b; i--)

int n,k;
string a[100100], b[100100], s;

int main()
{
    //freopen("text.inp","r",stdin);

    cin>>n;
    For(i,1,n)
    {
        cin>>a[i];
        cin>>b[i];
        if (a[i]>b[i]) {s=a[i]; a[i]=b[i]; b[i]=s;}
        getchar();
    }
//    For(i,1,n) cout<<a[i]<<" "<<b[i]<<"\n";
    s='@';
    For(i,1,n)
    {
        cin>>k;
        if (b[k]<s) {cout<<"NO"; return 0;}
        if (a[k]>s) s=a[k]; else s=b[k];
        //cout<<s<<"\n";
    }
    cout<<"YES";


    return 0;
}
