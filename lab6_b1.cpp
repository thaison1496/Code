/** \author PhamThaiSon 14020800
    \brief cac ham nhap va in ma tran (a: co so hang, cot; b: khong co so hang, cot; c: dinh dang CSV)
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;

#define For(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define convert(ss, m) stringstream ss; ss << m


typedef vector<double> vd;

vector< vd > input_1a(char* filename){
    int nrow, ncol;
    double tmp;
    stringstream ss;

    ifstream f (filename);//, fstream:: in);
    if (!f.is_open())
        throw ("file" + string(filename) + "cannot open");
    f >> nrow >> ncol;
    if (!f)
        throw ("file " + string(filename) + ": cannot read nrow, ncol");

    vector< vd > matrix;
    For(i,0,nrow){
        vd curr_row;
        For(j,0,ncol){
            f >> tmp;
             if (!f) {
                convert(ss, "file " << filename << ": cannot read position " << i+1 << ", " << j+1);
                throw (ss.str());
            }
            curr_row.pb(tmp);
        }
        matrix.pb(curr_row);
    }
    return matrix;
}


vector< vd > input_1b(char* filename){
    int ncol = -1, n_curr;
    double tmp;
    string line;

    ifstream f (filename);//, fstream:: in);
    if (!f.is_open())
        throw ("file" + string(filename) + "cannot open");
    vector< vd > matrix;
    while (!f.eof()){
        getline(f,line);
        if (line == "") break;
        stringstream ss(line);
        vd curr_row;
        n_curr = 0;

        while (ss >> tmp){
            n_curr += 1;
            curr_row.pb(tmp);
        }
        if (ncol == -1)
            ncol = n_curr;
        else
            if (ncol != n_curr)
                throw string("number of columns mismatches");
        matrix.pb(curr_row);
    }
    return matrix;
}


vector< vd > input_1c(char* filename){
    int ncol = -1, n_curr;
    double tmp;
    string line;

    ifstream f (filename);//, fstream:: in);
    if (!f.is_open())
        throw ("file" + string(filename) + "cannot open");
    vector< vd > matrix;
    while (!f.eof()){
        getline(f,line);
        if (line == "") break;
        For(i,0,line.length())
            if (line[i] == ',')
                line[i] = ' ';
        stringstream ss(line);
        vd curr_row;
        n_curr = 0;

        while (ss >> tmp){
            n_curr += 1;
            curr_row.pb(tmp);
        }
        if (ncol == -1)
            ncol = n_curr;
        else
            if (ncol != n_curr)
                throw string("number of columns mismatches");
        matrix.pb(curr_row);
    }
    return matrix;
}

void print_matrix(vector<vd> matrix, string split){
    For(i,0,matrix.size()){
        For(j,0,matrix[i].size()){
            cout << matrix[i][j];
            if (j < int(matrix[i].size()) - 1)
                cout << split;
        }

        cout << endl;
    }
}
int main(){
    vector<vd> a;
    try {
        a = input_1a("text.txt");
        print_matrix(a," ");
        a = input_1b("text.txt");
        print_matrix(a," ");
        a = input_1c("text.txt");
        print_matrix(a,",");
    } catch (string msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}
