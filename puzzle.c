#include <stdio.h>
#include <string.h>

//using namespace std;

typedef intarr[1400];
char a[110][110];
char b[1250][220];
int m, n, k, m1, n1;
intarr ihead, jhead, ivector, jvector;
int flag;


int nhap(){

    scanf("%d%d",&m,&n);
    m1 = m;
    n1 = n;
    getchar();
    //printf("%d%d",m,n);
    int i, j;
    for(i = 1; i <= m; i++){
        for( j = 1; j <= n; j++)
            a[i][j] = getchar();
        getchar();
    }
    return 0;
}

int ad(int i, int j, int ii, int jj, int round){
    k ++ ;
    ihead[k] = i;
    jhead[k] = j;
    ivector[k] = ii;
    jvector[k] = jj;
    int t = 0;
    while (i > 0 && i <= m && j > 0 && j <= n){
        b[k][t] = a[i][j];
        i += ii;
        j += jj;
        t ++;
    }
    if (round == 1){
        int p;
        for (p = t; p < 2*t; p++)
            b[k][p] = b[k][p-t];
        t *= 2;
    }
    b[k][t] = '\0';
    return 0;
}
int init(){
    int i, j;
    k = 0;

    //duong ngang
    for(i = 1; i <= m; i++)
    {
        ad(i,1,0,1,1);
        ad(i,n,0,-1,1);
    }

    //duong doc
    for(j = 1; j <= n; j++)
    {
        ad(1,j,1,0,1);
        ad(m,j,-1,0,1);
    }

    //duong cheo
    for(i = 1; i <= m; i++)
    {
        ad(i,1,1,1,0);
        ad(i,1,-1,1,0);
        ad(i,n,-1,-1,0);
        ad(i,n,1,-1,0);
    }
    for(j = 1; j <= n; j++)
    {
        ad(1,j,1,1,0);
        ad(1,j,1,-1,0);
        ad(m,j,-1,-1,0);
        ad(m,j,-1,1,0);
    }
    //printf("%d",k);
    /*
    for(i = 1; i <= k; i++){
        for( j = 1; j <= b[i][0]; j++)
            printf("%c",b[i][j]);
        printf("\n");
    }
 /*   for(i = 1; i <= m; i++){
        for( j = 1; j <= n; j++)
            printf("%c",a[i][j]);
        printf("\n");
    }*/

    return 0;
}

int inkq(int p, int k, int si, int sj, int ii, int jj){
    si += p*ii;
    sj += p*jj;
    int fi = si + k*ii;
    int fj = sj + k*jj;
    if (fi > m1){
        fi -= m1;
        si = -si;
        sj = -sj;
        fi = -fi;
        fj = -fj;
    }
    else if (fj > n1){
        fj -= n1;
        si = -si;
        sj = -sj;
        fi = -fi;
        fj = -fj;
    }
    else if (fi < 1){
        fi += m1;
        si = -si;
        sj = -sj;
        fi = -fi;
        fj = -fj;
    }
    else if (fj < 1){
        fj += n1;
        si = -si;
        sj = -sj;
        fi = -fi;
        fj = -fj;
    }
    printf("%d %d %d %d\n",si,sj,fi,fj);
    return 0;
}
int kmp(char p[], char t[], int id){
    //printf("%s\n",t);
    int m = strlen(p);
    int n = strlen(t);
    //printf("%d%d",m,n);
    int f[220];
    int i = 0;
    int k;

    f[0] = -1;
    for (i = 1; i < m; i++){
        k = f[i - 1];
        while (k >= 0){
            if (p[k] == p[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
    i = 0;
    k = 0;
    while (i < n){
        if (k == -1){
            i++;
            k = 0;
        }
        else if (t[i] == p[k]){
            i++;
            k++;
            if (k == m){
                flag = 1;
                //printf("%s\n",b[id]);
                inkq(i-m, m-1, ihead[id], jhead[id], ivector[id], jvector[id]);
                return 0;
            }
        }
        else
            k = f[k];
    }
    return 0;
}

int check(char p[]){
    int i;
    for(i = 0; i < strlen(p); i++)
        if (!( (p[i]>='A' && p[i]<='Z') || (p[i]>='a' && p[i]<='z') ))
            return 0;
    return 1;
}
int query(){
    int q;
    int i;
    char p[100];
    scanf("%d\n",&q);
    while (q--){
        //scanf("%s\n",&p);
        gets(p);
        //printf("%s\n",p);
        if (check(p) == 0){
            printf("input error\n");
            continue;
        }
        flag = 0;
        for (i = 1; i<=k; i++){
            //printf("%s",p);
            kmp(p,b[i],i);
            if (flag == 1) break;
        }
        if (flag == 0)
            printf("not found\n");
    }
    return 0;
}

int main(){
    freopen("puzzle.inp","r",stdin);
    //freopen("puzzle.out","w",stdout);
    nhap();
    init();
    query();
    return 0;
}
