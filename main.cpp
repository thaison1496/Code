#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <sstream>

using namespace std;

#define FOR(i, f, l) for (int i = (int)(f); i != (int)(l); i++)
#define CONVERT(ss, m) stringstream ss; ss << m
#define GETLINE(f, line) string line; getline(f, line)

class Matrix : public vector<vector<double> >
{
public:
    int n_row() { return size(); }
    int n_col() { assert(size() > 0); return at(0).size(); }
};

class MatrixVec : public vector<double>
{
    int n_row, n_col;
public:
    int get_nrow() { return n_row; }
    int get_ncol() { return n_col; }
};

class MatrixArr
{
    double* val;
    int n_row, n_col;
public:
    MatrixArr(int n_row, int n_col);
    MatrixArr();

    int get_nrow() { return n_row; }
    int get_ncol() { return n_col; }
    void setAll(double v);
    double get(int i, int j);

    void nhap_1a(const char* fname);
    void nhap_1b(const char* fname);
    void in_matran();
};

MatrixArr::MatrixArr()
{
    this->n_row = -1;
    this->n_col = -1;
    val = NULL;
}

MatrixArr::MatrixArr(int n_row, int n_col)
{
    this->n_row = n_row;
    this->n_col = n_col;
    val = new double[n_row * n_col];
}

double MatrixArr::get(int i, int j)
{
    if (i < 0 || j < 0 || i >= n_row || j >= n_col)
    {
        CONVERT(ss,"invalid position " << i << ", " << j);
        throw (ss.str());
    }
    return val[i * n_col + j];
}

void MatrixArr::setAll(double v)
{
    FOR(i, 0, n_row * n_col)
        val[i] = v;
}

void MatrixArr::nhap_1a(const char* fname)
{
    ifstream f(fname);
    if (!f.is_open())
        throw ("file " + string(fname) + ": cannot open");
    f >> n_row >> n_col;
    if (!f)
        throw ("file " + string(fname) + ": cannot read n_row, n_col");
    if (!val) delete val;
    val = new double[n_row * n_col];
    int k = 0;
    FOR(i, 0, n_row)
        FOR(j, 0, n_col) {
            f >> val[k];
            if (!f) {
                CONVERT(ss, "file " << fname << ": cannot read position " << i << ", " << j);
                throw (ss.str());
            }
            k++;
        }
}

void MatrixArr::nhap_1b(const char* fname)
{
    ifstream f(fname);
    if (!f.is_open())
        throw ("file " + string(fname) + ": cannot open");

    double tmp;
    int count = 0;
    int cur_row = 0;
    int input_n_col = 0;
    while (!f.eof()) {
        GETLINE(f, line);
        stringstream ss(line);
        /* read a line and compute number of columns */
        int ss_col = 0;
        while (ss) {
            ss >> tmp;
            if (ss) {
                count++;
                ss_col++;
            }
            else
                if (!ss.eof()) throw string("error reading file ") + fname;
        }
        // check if number of columns mismatches
        if (ss_col != 0) {
            if (cur_row == 0) input_n_col = ss_col;
            else if (input_n_col != ss_col)
                throw string("number of columns mismatches");
        } else { // check if empty line at the middle of file
            if (f.eof()) {
                n_row = cur_row;
                n_col = input_n_col;
            } else
                throw string("empty line");
        }
        cur_row++;
    }
    // allocate memory and read the file again
    val = new double[count];
    f.clear();
    f.seekg(0, ios::beg);
    int k = 0;
    FOR(i, 0, n_row)
        FOR(j, 0, n_col) f >> val[k++];
}


void MatrixArr::in_matran()
{
    int k = 0;
    FOR(i, 0, n_row) {
        FOR(j, 0, n_col) {
            cout << val[k] << " ";
            k++;
        }
        cout << endl;
    }
}

int main()
{
    MatrixArr a(1,1);
    try {
        //a.nhap_1a("text.txt");
        a.nhap_1b("text.txt");
        a.in_matran();
    } catch (string msg) {
        cout << "Got exception: " << msg << endl;
    }
    return 0;
}
