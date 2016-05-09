#include <stdio.h>
#include <limits.h>

int main(){

    int i,n,mi,mx,count,s;
    int a[100100];
    printf("n = "); scanf("%d/n",&n);
    mx=INT_MIN; mi=INT_MAX; count=0; s=0;
    for(i=0; i<n; i++){
        printf("a[%d",i); printf("] = "); scanf("%d\n",&a[i]);
        if (a[i]<mi) mi = a[i];
        if (a[i]>mx) mx = a[i];
        if (a[i]%2==0) s+=a[i]; else count+=1;
    }

    printf("Phan tu nho nhat: %d\n",mi);
    printf("Phan tu lon nhat: %d\n",mx);
    printf("Tong cac phan tu chan: %d\n",s);
    printf("So phan tu le: %d\n",count);

    return 0;
}
