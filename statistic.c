#include <stdio.h>
#include <limits.h>
#include <math.h>

double s=0;
int input_array(double a[], int n){
    int i;
   // printf(("%d/n",&n));
   // printf("n = "); scanf("%d/n",&n);
    //printf("%d",n);
    for(i=0; i<n; i++){
        scanf("%lf",&a[i]);
    }
    return 0;
}

int average(double a[], int n){
    int i;
    for(i=0; i<n; i++){
        s+=a[i];
    }
    printf("Ki vong cua day so: %0.3lf\n",s/ n);
    return 0;
}

int standard_deviation(double a[], int n){
    double o=0;
    int i;
    for(i=0; i<n; i++){
        o+=(a[i]-s/ n)*(a[i]-s/ n);
    }
    o=sqrt(o/ n);

    printf("Do lech chuan cua day so: %0.3lf\n",o);

    return 0;
}
int main(){

    int i,n;

    double a[100100];
    printf("n = "); scanf("%d",&n);
    input_array(a,n);
    average(a,n);
    standard_deviation(a,n);
    return 0;
}
