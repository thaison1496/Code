#include <iostream>
#include <cmath>

double a,b,c,d;
int main(){

    std::cin>>a>>b>>c;
    if (a==0){
        if (b==0){
            if (c==0)
                std::cout<<"Vo so nghiem ";
            else
                std::cout<<"Vo nghiem ";
        }
        else
            std::cout<<"Nghiem x="<<-c/b;
    }
    else{
        d=b*b-4*a*c;
        if (d<0){
            std::cout<<"Vo nghiem ";
        }
        else if (d==0){
            std::cout<<"Nghiem x="<<-b/2/a;
        }
        else{
            std::cout<<"Nghiem x1="<<(-b-sqrt(d))/2/a<<", x2="<<(-b+sqrt(d))/2/a;
        }
    }
    return 0;
}
