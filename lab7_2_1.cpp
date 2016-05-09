#include <iostream>
#include <cmath>

using namespace std;

#define For(i,a,b) for(int i = a; i < b; i ++ )

class NhanVien{
public:
    int age, salary;
    string name;

    NhanVien(){
    }

    NhanVien(string name, int age, double multi, double extra){
        this->name = name;
        this->age = age;
        this->salary = round( multi * 1050 + extra );
    }


    friend ostream& operator << (ostream& os, NhanVien& a){
        os << "Ten: " << a.name << endl;
        os << "Tuoi: " << a.age << endl;
        os << "Luong: " << a.salary << endl;
        return os;
    }


    friend istream& operator >> (istream& is, NhanVien& a){
        double multi, extra;
        cout << "Nhap ten: ";
        is >> a.name;
        cout << "Nhap tuoi: ";
        is >> a.age;
        cout << "Nhap he so: ";
        is >> multi;
        cout << "Nhap phu cap: ";
        is >> extra;
        a.salary = round( multi * 1050 + extra );
        return is;
    }
};

/*
NhanVien nvcopy(NhanVien& a){
    NhanVien *tmp = new NhanVien();
    //NhanVien tmp();
    tmp->name = a->name;
    tmp->age = a->age;
    tmp->salary = a->salary;
    return tmp;
}

*/



int main(){
    NhanVien a = NhanVien();//"son",11,10,1000000
    NhanVien b = NhanVien();
    cin >> a >> b;
    cout << a << b;
    return 0;
}
