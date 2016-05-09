#include<stdio.h>
#include<conio.h>
void nhap(int &n)
{
    int i = 2;
    if (n == i) n ++;
    printf("n= ");
    scanf("%d",&n);
}
int main(void)
{
    int n=8;
    nhap(n);
    printf("n= %d",n);
    getch();
    return 0;
}
