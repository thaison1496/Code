#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for(int i = a; i < b; i ++)
#define fi first
#define se second
#define pb push_back
#define Rep(i,a) for(int i = 0; i < int( a.size() ) ; i++)
#define reset(a,x) memset(a,x,sizeof(a));

typedef pair<int, int> pii;
typedef vector<int> vi;

int ip[1010], a[1010], c[1010];
int m,n,cnt,r,tmp;
bool mark[1010][1010];
vi ls;

int fin(int t){
    int l = 0;
    int h = n - 1;
    while (h >= l){
        //cout << l << " " << h << " " << m << endl;
        m = (h+l)/2;
        if (a[m] == t)
            return m;
        if (a[m] < t)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int check(int i, int j){
    if (i == j && c[i] < 2)
        return 2;
    tmp = 2;
    mark[i][j] = true;

    ls.clear();
    ls.pb(i);
    ls.pb(j);

    c[i] -- ;
    c[j] -- ;
    while (true) {
        int k = fin(a[i] + a[j]);
            //cout << i << j << k << endl;
        if (k == -1 || c[k] == 0)
            break;
        c[k] -- ;
        ls.pb(k);
        tmp += 1;

        //if (tmp == 3)
         //   cout << i << j << k << endl;

        i = j;
        j = k;
        mark[j][k] = true;
    }
    Rep(i,ls){
        c[ls[i]] ++ ;
        //cout << ls[i] << " ";
    }
    /*cout << "zz" << endl;
    For(i,0,n)
        cout << c[i] << " ";
    cout << endl;*/
    return tmp;
}

int main(){
    //freopen("text.txt","r",stdin);
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> ip[i];
    }
    sort(ip, ip+m);

    cnt = 0;
    n = 0;
    ip[m] = 1000000001;
    For(i,0,m+1){
        if (i > 0 && ip[i] != ip[i-1]){
            a[n] = ip[i-1];
            c[n] = cnt;
            cnt = 0;
            n ++ ;
        }
        cnt ++ ;
    }
    /*For(i,0,n)
        cout << a[i] << " " << c[i] << endl;*/

    //cout << fin(a[0] + a[4]);
    reset(mark, 0);
    r = 0;
    For(i,0,n)
        For(j,0,n)// if (mark[i][j] == false)
            r = max(r, check(i,j));
    cout << r;
    return 0;
}
