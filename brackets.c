#include <stdio.h>
#include <limits.h>

int main(){

    int n,i,s;
    char c;
    s=0;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++){
        c=getchar();
        if (c=='(') s++; else s--;
        if (s<0){
            printf("no");
            return 0;
        }
    }
    if (s!=0) printf("no"); else printf("yes");
    return 0;
}
