/** \author: son14020800
    \brief: dem so lan xuat hien cua 1 xau con trong xau da cho
*/
#include <iostream>
#include <cstring>
using namespace std;

#define For(i, a, b) for(int i = a; i <= b; i++)

/** \brief: dem so lan xuat hien cua xau thu nhat trong xau thu 2
    \param s: xau thu nhat
    \param t: xau thu hai
    \return so lan xuat hien cua s trong t
*/
int dem(string s, string t){
    int m = s.length() - 1;
    int n = t.length() - 1;
    int ct = 0;
    For(i, 0, n-m)
        if (t.substr(i,m+1) == s)
            ct ++;
    return ct;

}
int main(){
    string s,t;
    getline(cin,s);
    getline(cin,t);

    //cout<<m<<n;
    cout<< dem(s,t);
    return 0;
}

