#include <bits/stdc++.h>

using namespace std;

int main(){

    //freopen("text.txt","r",stdin);
    string t,p;
    int m,n,k;
    int f[100100];

    //t = ""; p = "";
    //for(int i = 0; i < 100000; i++) t+="i";
    //for(int i = 0; i < 100000; i++) p+="i";

    getline(cin,t);
    getline(cin,p);
    m = t.length();
    n = p.length();

    f[0] = -1;
    k = 0;
    for(int i = 1; i < n; i++){
         k = f[i-1];
                while (k>=0)
                {
                        if (p[k]==p[i-1])
                                break;
                        else
                                k = f[k];
                }
                f[i] = k + 1;
    }

    k = 0;
    int last = -1;
    int r = 0;
    for(int i = 0; i < m; i++){
            while (k>0 && t[i] != p[k])
                k = f[k];
            if (p[k] == t[i])
                k ++ ;
            if (k == n){
                if (i - k + 1 > last){
                    last = i;
                    r ++ ;
                }
            }
    }
    cout << r;
    return 0;
}

