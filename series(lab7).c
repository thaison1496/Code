#include <stdio.h>
int main(){
    char a[10000];
    int i, n, x=0, c=0, s=0, d=1;

    gets(a);
    n=strlen(a);

    for(i=0; i<n; i++){
        if (a[i]=='-') d=-1;
        else
        if (a[i]>='0' && a[i]<='9') x=x*10+a[i]-48;
        else
        if (i>0 && a[i-1]>='0' && a[i-1]<='9') {
            c++;
            s+=x*d;
            x=0;
            d=1;
        }
    }
    printf("%d %d",c,s);

    return 0;
}


