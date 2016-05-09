/** \author PhamThaiSon 14020800
    \brief class nhap va in ra 1 ds sinh vien: ten, tuoi, [ten mon hoc, diem mon hoc]; dinh dang CSV
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
#include <utility>
#include <string>

using namespace std;

#define For(i, a, b) for(int i = a; i < b; i++)
#define pb push_back

class Diem{
public:
    vector< string > subject_name;
    vector< int > subject_score;
};

string parse(string s, int& i){
    string t = "";
    int n = s.length();
    while (true){
        if (i == n || s[i] == ','){
            i ++;
            return t;
        }
        t += s[i];
        i ++;
    }
}

class SinhVien{
public:
    string name;
    int age;
    Diem score;

    static vector< SinhVien > nhapds(char* filename);
    static void inds(vector< SinhVien > ds);
    SinhVien(string s){
        int i = 0;
        double sscore;
        string sname;

        name = parse(s,i);
        stringstream ss(parse(s,i));
        if (!(ss >> age))
            throw string("Error reading file");

        while (i < s.length()){
            sname = parse(s,i);
            stringstream ss(parse(s,i));
            if (!(ss >> sscore))
                throw string("Error reading file");

            score.subject_name.pb(sname);
            score.subject_score.pb(sscore);
        }
    }

    void inkq(){
        cout << name << "," << age << ",";
        For(i,0,score.subject_name.size()){
            cout << score.subject_name[i] << "," << score.subject_score[i];
            if (i < int(score.subject_name.size()) - 1)
                cout << ",";
        }
        cout << endl;
    }
};


vector< SinhVien > SinhVien::nhapds(char* filename){
    fstream f (filename, fstream::in);
    vector< SinhVien > ds;
    string line;

    while (!f.eof()){
        getline(f,line);
        if (line == "") break;
        if (line[0] == '#') continue;
        SinhVien sv(line);
        ds.pb(sv);
    }
    return ds;
}


void SinhVien::inds(vector< SinhVien > ds){
    For(i,0,ds.size())
        ds[i].inkq();
}


int main(){
    vector< SinhVien > ds;
    try {
        ds = SinhVien::nhapds("text.txt");
        SinhVien::inds(ds);
    } catch (string msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}


