#include <stdio.h>
#include <limits.h>

int i;
double d[6];
int inkq(int k)
{
    printf("%d\n",k);
    if (k>0){
        for(i=1; i<=k; i++) printf("%.3f ",d[i]);
        printf("\n");
    }
}
int solve(double a, double b, double c){
    double delta = b*b-4*a*c;
    double x1,x2;
    int k=0;



    if (delta<0) {
        inkq(k);
        return 0;
    }
    if (delta>0){
        k=0;
        x1=(-b-sqrt(delta))/(2*a);
        x2=(-b+sqrt(delta))/(2*a);
        if (x1>0){
            d[++k]=sqrt(x1);
            d[++k]=-sqrt(x1);
        }
        else if (x1==0) d[++k]=0;
        if (x2>0){
            d[++k]=sqrt(x2);
            d[++k]=-sqrt(x2);
        }
        else if (x2==0) d[++k]=0;
        inkq(k);
        return 0;
    }

    x1=-b/(2*a);
    if (x1<0){
        inkq(k);
        return 0;
    }
    if (x1==0){
        d[++k]=0;
        inkq(k);
        return 0;
    }
    if (x1>0){
        d[++k]=sqrt(x1);
        d[++k]=-sqrt(x1);
        inkq(k);
    }

    return 0;
}
int main(){
    int n;
    double a,b,c;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        solve(a,b,c);
    }
    return 0;
}

