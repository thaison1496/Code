#include <stdio.h>
int main(){
    int i,m,n,count=0;
    int pos[600];
    char a[31], c[31];
    char b[513];

    gets(a); gets(b);

    m=strlen(a); n=strlen(b);
    for(i=0; i<=n-m; i++){
        strncpy(c,b+i,m);
        if (strcmp(a,c)==0) {
            pos[count]=i;
            count+=1;
        }
    }

    printf("%d\n",count);
    for(i=0; i<count; i++) printf("%d\n",pos[i]);

    return 0;
}

