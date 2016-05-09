#include <stdio.h>
#include <limits.h>

int main(){

    int m,n,i,j,x,c;
    int a[101][101];
    int di[4] = {0,1,0,-1};
    int dj[4] = {1,0,-1,0};

    //printf("%d %d ",di[2],dj[2]);
    scanf("%d%d",&m,&n);
    for(i=0; i<=m+1; i++)
        for(j=0; j<=n+1; j++) a[i][j]=1;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++) a[i][j]=0;

    i=1;
    j=1;
    c=0;
    x=0;
    while (c<m*n){
        c++;
        a[i][j]=1;
        printf("%d ",(i-1)*n+j);
        i+=di[x];
        j+=dj[x];
        if (a[i][j]==1){
            i-=di[x];
            j-=dj[x];
            x=(x+1)%4;
            i+=di[x];
            j+=dj[x];
        }
    }
    return 0;
}

