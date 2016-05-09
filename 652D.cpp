#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for(int i = a; i < b; i ++)
#define fi first
#define se second
#define pb push_back
#define Rep(i,a) for(int i = 0; i < int( a.size() ) ; i++)
#define reset(a,x) memset(a,x,sizeof(a));

typedef pair<pair<int, int>,int> piii;
typedef vector<int> vi;

int n;
piii a[200100];
int p[200100], s[200100], r[200100];

bool sortLeft(piii a, piii b){
    return a.fi.fi > b.fi.fi;
}

bool sortRight(piii a, piii b){
    return a.fi.se < b.fi.se;
}

int get(int i){
    int sum = 0;
    while (i>0){
        sum += s[i];
        i -= i & (-i);
    }
    return sum + s[0];
}

int update(int i){
    if (i==0){
        s[0] ++ ;
        return 0;
    }

    while (i<n){
        s[i] ++ ;
        i += i & (-i);
    }
    return 0;
}

int main(){
    //freopen("text.txt","r",stdin);
    cin >> n;
    For(i,0,n){
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }
    sort(a,a+n,sortRight);
    For(i,0,n)
        p[a[i].se] = i;
    sort(a,a+n,sortLeft);
    //For(i,0,n)
        //cout << a[i].fi.fi << " " << a[i].fi.se << endl;

    memset(s,0,sizeof(s));
    For(i,0,n){
        r[a[i].se] = get(p[a[i].se]);
        //cout << a[i].se << " " << p[a[i].se] << endl;
        update(p[a[i].se]);
    }

    For(i,0,n)
        cout << r[i] << endl;
}
