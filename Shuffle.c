#include <stdio.h>
#include <limits.h>

int main(){

    int n,i,x,y,flag;
    int a[2][201];
    scanf("%d/n",&n);

    for(i=1; i<=2*n; i++) {
        a[0][i]=i;
    }

    x=0; y=1;
    a[0][0]=-1;
    a[1][0]=-1;

    int c=0;
    while (1){
        c++;
        for(i=1; i<=2*n; i++)
            if (i%2==0) a[y][i]=a[x][i/2];
            else a[y][i]=a[x][i/2+n+1];
        flag=0;
        for(i=1; i<=2*n; i++)
        {
            if (a[y][i]<a[y][i-1]) flag=1;
        }
        if (flag==0) break;

        x=1-x;
        y=1-y;
    }

    printf("%d\n",c);

    for(i=1; i<=2*n; i++) {
        a[0][i]=i;
        printf("%d ",i);
    }
    printf("\n");
    x=0; y=1;

    while (1){
        for(i=1; i<=2*n; i++)
            if (i%2==0) a[y][i]=a[x][i/2];
            else a[y][i]=a[x][i/2+n+1];
        flag=0;
        for(i=1; i<=2*n; i++)
        {
            printf("%d ",a[y][i]);
            if (a[y][i]<a[y][i-1]) flag=1;
        }
        printf("\n");
        if (flag==0) break;

        x=1-x;
        y=1-y;
    }


    return 0;
}

