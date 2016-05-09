#include<bits/stdc++.h>

using namespace std;

int ct, r, n, sum, t;
int a[200100], dd[200100];

int check(int p, int i, int j){
    if (p % 2 == 0){
        if (a[i] > a[j])
            return 1;
        else
            return 0;
    }
    else{
        if (a[i] < a[j])
            return 1;
        else
            return 0;
    }
}

int main(){
  //  freopen("text.txt","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if (n % 2 == 0)
        a[n + 1] = 0;
    else
        a[n + 1] = 200000;
    a[0] = 200000;

    ct = 0;
    r = 0;
    for(int i = 1; i <= n; i++)
        if (check(i,i,i+1) == 0)
            ct += 1;
    //cout << ct << endl;
    if (ct >= 5){
        cout << 0;
        return 0;
    }
    memset(dd,0,sizeof(dd));
    for(int i = 1; i <= n; i++) if (check(i,i,i+1) == 0 || check(i-1,i-1,i) == 0){
        dd[i] = 1;
        for(int j = 1; j <= n; j++) if (i!=j && !(i > j && dd[j])){
            //sum = check(i-1,i-1,j) - check(i-1,i-1,i) + check(i,j,i+1) - check(i,i,i+1)
            //    + check(j-1,j-1,i) - check(j-1,j-1,j) + check(j,i,j+1) - check(j,j,j+1);
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            sum = check(i-1,i-1,i) + check(i,i,i+1) + check(j-1,j-1,j) + check(j,j,j+1);
            if (i == j-1)
                sum -= check(i,i,i+1);
            if (i == j+1)
                sum -= check(i-1,i-1,i);

            t = a[i];
            a[i] = a[j];
            a[j] = t;
            sum -= check(i-1,i-1,i) + check(i,i,i+1) + check(j-1,j-1,j) + check(j,j,j+1);
            if (i == j-1)
                sum -= check(i,i,i+1);
            if (i == j+1)
                sum -= check(i-1,i-1,i);

//cout << i << " " << j << " " << sum << endl;
            if (sum == ct){
                r ++;
            }
        }
    }
  //  cout << check(1,2,2) - check(1,1,2) << endl;
    cout << r;
    return 0;
}
