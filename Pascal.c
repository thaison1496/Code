#include <stdio.h>
#include <limits.h>

int main(){

    int i,n,j;
    int a[101][101];
    printf("n = "); scanf("%d/n",&n);
    a[0][0]=1;
    printf("    1\n");
    for(i=1; i<=n; i++)
    {
        a[i][0]=1;
        for(j=1; j<i; j++) a[i][j]=a[i-1][j]+a[i-1][j-1];
        a[i][i]=1;
        for(j=0; j<=i; j++) printf("%5d",a[i][j]);
        printf("%\n");
    }

    return 0;
}

