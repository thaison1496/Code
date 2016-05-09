/** \author PhamThaiSon 14020800
    \brief class xu ly ma tran thua
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
#include <utility>
using namespace std;

#define For(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define convert(ss, m) stringstream ss; ss << m
#define mp make_pair
#define fi first
#define se second

typedef pair<double, int> pdi;
typedef vector< pdi > vpdi;

class SparseMatrix{
public:
    int nrow = 0, ncol = 0;
    vector< vpdi > matrix;
    void input(char* filename);
    void print_matrix();
    double get(int i, int j);
};


void SparseMatrix::input(char* filename){
    double t1;
    int t2;
    string line;

    ifstream f (filename);//, fstream:: in);
    if (!f.is_open())
        throw ("file " + string(filename) + " cannot open");

    while (!f.eof()){
        getline(f,line);
        For(i,0,line.length())
            if (line[i] == ':')
                line[i] = ' ';
        if (line == "") break;

        stringstream ss(line);
        vpdi curr_row;
        nrow ++;

        while (ss >> t2 >> t1){
            curr_row.pb(mp(t1,t2));
            ncol = max(ncol, t2);
        }
        matrix.pb(curr_row);
    }
}


void SparseMatrix::print_matrix(){
    For(i,0,matrix.size()){
        For(j,0,matrix[i].size()){
            cout << matrix[i][j].se << ":" << matrix[i][j].fi << " ";
        }
        cout << endl;
    }
}

double SparseMatrix::get(int i, int j){
    if (i>=ncol || i<0 || j>=nrow || j<0)
        throw("Index out of range");
    For(k,0,matrix[i].size())
        if (matrix[i][k].se == j)
                return matrix[i][k].fi;
    return 0;
}

SparseMatrix operator +(SparseMatrix &mt1, SparseMatrix &mt2){
    int j,k;
    vector < vpdi > a = mt1.matrix;
    vector < vpdi > b = mt2.matrix;

    if (mt1.nrow != mt2.nrow || mt1.ncol != mt2.ncol)
        throw string("Matrix size error");
    vector < vpdi > c;
    SparseMatrix r;
    r.nrow = mt1.nrow;
    r.ncol = mt1.ncol;
    c.resize(r.nrow);

    For(i,0,r.nrow){
        j = 0;
        k = 0;
        //cout << i << a[i].size() << b[i].size() << endl;
        while ( !(j == a[i].size() && k == b[i].size()) ){
            //cout << i << " " << a[i][j].se << " " << b[i][k].se << endl;
            if (j == a[i].size()){
                c[i].pb(b[i][k]);
                k ++;
                continue;
            }
            if (k == b[i].size()){
                c[i].pb(a[i][j]);
                j ++;
                continue;
            }
            if (a[i][j].se == b[i][k].se){
                c[i].pb( mp(a[i][j].fi + b[i][k].fi, a[i][j].se) );
                j ++;
                k ++;
                continue;
            }
            if (a[i][j].se < b[i][k].se){
                c[i].pb(a[i][j]);
                j ++;
                continue;
            }
            if (a[i][j].se > b[i][k].se){
                c[i].pb(b[i][k]);
                k ++;
                continue;
            }
        }
    }
    r.matrix = c;
    return r;

}


int main(){
    SparseMatrix a;
    SparseMatrix b;
    try {
        a.input("text.txt");
        a.print_matrix();
        cout << a.get(1,2);
        cout << endl;
        b.input("text2.txt");
        b.print_matrix();
        cout << endl;
        //SparseMatrix (a+b).print_matrix();
        SparseMatrix c = SparseMatrix (a+b);
        c.print_matrix();

    } catch (string msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}

