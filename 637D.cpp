#include <bits/stdc++.h>

using namespace std;

int n,m,s,d;
int last, num_gap, x;
int a[200100];
pair<int,int> gaps[200100];

int main(){


    //freopen("text.txt","r",stdin);
    cin >> n >> m >> s >> d;
    last = -1;
    num_gap = 0;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    //for(int i = 0; i < n; i++)
    //    cout << a[i];
    for(int i = 0; i < n; i++){
        x = a[i];
        if (x - last - 1 > s){
            gaps[num_gap].first = last;
            gaps[num_gap].second = x;
            //cout << gaps[num_gap].first << " " << gaps[num_gap].second << endl;
            num_gap ++ ;
            if (num_gap > 1 && gaps[num_gap-1].first + 2 - gaps[num_gap-2].second > d){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        last = x;
    }

    if (n == 0){
        cout << "RUN " << m;
        return 0;
    }
    if (gaps[0].first != -1 || d <= 1 || a[n-1] + 2 - gaps[num_gap - 1].second > d){
        cout << "IMPOSSIBLE";
        return 0;
    }

    gaps[0].first = -1;
    for(int i = 0; i < num_gap; i++){
        cout << "RUN " << gaps[i].second - gaps[i].first - 2 << endl;
        if (i < num_gap - 1){
            cout << "JUMP " << gaps[i+1].first + 2 - gaps[i].second << endl;
        }
    }
    cout << "JUMP " << a[n-1] + 2 - gaps[num_gap - 1].second << endl;
    if (m > a[n-1] + 1)
        cout << "RUN " << m - a[n-1] - 1;

    return 0;
}
