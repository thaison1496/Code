#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)
#define ForD(i,a,b) for(int i=a; i>=b; i--)

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

class mystr{
public:
    char* data;
    mystr(){
    }
    mystr(char* s){
        data = s;
    }
    ~mystr(){
        if (!data)
            delete data;
    }
};
ostream& operator << (ostream& os, const mystr &Mystr){
        if (Mystr.data)
            os << Mystr.data;
        return os;
    }

class Base{

public:
    int dat;
    Base() {dat = 0;}
    Base(int x){
        dat = x;
    }
    void printout(){
        cout << dat;
    }
};

class A : public Base{
public:
    int n;
    A(int n1, int d): Base(d){
        n = n1;
    }
    void printout(){
        cout<<dat<<" "<<n;
    }
};

class hinh{
public:
    int socanh;
    hinh(){socanh = 0;}
    hinh(int x){socanh = x;}
    void pr(){
        cout << "So canh: "<<socanh;
    }
};

class tamgiac: public hinh{
public:
    int socanh;
    double c1,c2,c3;
    tamgiac(double x1, double x2, double x3):hinh(3){
        c1 = x1;
        c2 = x2;
        c3 = x3;
    }
    void vehinh(){
        cout << "Day la tam giac :'( ";
    }
};

class hinhvuong: public hinh{
public:
    int socanh;
    double c;
    hinhvuong(double x):hinh(3){
        c = x;
    }
    void vehinh(){
        cout << "Day la hinh vuong :'( ";
    }
};

template <class T>
class myclass{
public:
    int x = 2;
    void test(T x){
        cout << x;
    }
};


int main()
{
    //tamgiac tg(1,1,1);
    //tg.vehinh();
    //hinhvuong v(2);
    //v.vehinh();
    myclass<int> m;
    m.test(3);
    return 0;
}
