#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
    ifstream is ("text.txt", ifstream:: binary);
    if (is) {
        int a[] = {1,2,3,4};
        fstream f ("text.txt", fstream:: binary | fstream:: out);
        f.write( (char*) a, sizeof(a));
        f.close();

        ifstream g ("text.txt", ifstream:: binary);
        int x1[1], x2[1];
        g.read((char*) x1, sizeof(x1));
        g.seekg(12, g.beg);
        g.read((char*) x2, sizeof(x2));
        g.close();

        f.open("text.txt");
        f.seekp(0, f.beg);
        f.write( (char*) x2, sizeof(x2));
        f.seekp(12, f.beg);
        f.write( (char*) x1, sizeof(x1));
        f.close();

        int b[4];
        ifstream h ("text.txt", ifstream:: binary);
        h.read((char*) b, sizeof(b));
        for(int i = 0; i < 4; i++)
            cout << b[i] << endl;
        h.close();
  }
    return 0;
}
