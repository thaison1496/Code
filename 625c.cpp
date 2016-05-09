#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    int a[510][510];
    cin >> n >> k;
    k -- ;
    int curr = n*n, res = 0;
    memset(a,0,sizeof(a));
    for (int i = 0; i < n; i++)
        for(int j = n - 1; j >= k; j --){
            a[i][j] = curr;
            curr -- ;
            if (j == k)
                res += a[i][j];
        }
    for(int i = 0; i < n; i++)
        for(int j = k-1; j >= 0; j--){
            a[i][j] = curr;
            curr -- ;
    }
    cout << res << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }


    return 0;
}
