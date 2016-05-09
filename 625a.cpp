#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a,b,c,n,k1,k2;
    cin >> n >> a >> b >> c;
    if (n<a && n<b){
        k1 = 0;
        k2 = 0;
    }
    else
        if (n>=b) {
            k2 = (n-b)/(b-c)+1;
            k2 += (n - k2*b + k2*c)/a;
            k1 = n/a ;
        }
        else{
            k1 = n/a;
            k2 = 0;
        }



    cout << max(k1,k2);
    return 0;
}
