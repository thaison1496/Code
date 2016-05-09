/** \author: son14020800
    \brief: chuan hoa xau, dem so tu trong 1 xau, tra ve danh sach cac tu (dung cstring)
*/
#include <iostream>
#include <cstring>
using namespace std;

#define For(i, a, b) for(int i = a; i <= b; i++)

int nword = 0;
typedef struct Node {
    string word;
    Node *next;
};
/**
    \brief: chuan hoa xau (xoa dau cach dau, cuoi xau, xoa dau cach thua, in hoa chu cai dau tien moi tu, in thuong cac chu con lai)
    \details: dung 1 bien flag = true neu da co dau cach dung, false neu chua co, duyet qua xau a va them ki tu vao xau b theo bien flag
    \param a: xau nhap vao
    \return xau duoc chuan hoa
*/
char* chuanhoa(char* a){
    char* b = new char[100];
    int m = strlen(a);
    //cout << m;
    int n=0;
    bool flag = true;
    For(i, 0 , m-1)
        if (a[i] == ' '){
            if (not(flag)){
                b[n] = a[i];
                n++;
                flag = true;
            }
        }
        else{
            b[n] = a[i];
            if (flag){
                b[n] = toupper(b[n]);
                nword ++;
            }
            else
                b[n] = tolower(b[n]);
            n++;
            flag = false;
        }

    if (b[n-1] == ' ')
        b[n-1] = NULL;
    else
        b[n] = NULL;
    //b[0]='a'; b[1]='b';
    //cout<<b<<"zzz"<<endl;
    return b;
}

/**
    \brief: tra ra danh sach cac tu cua mot xau
    \param a: xau nhap vao
*/
Node* inds(char* a){
    Node* root;
    Node* p;
    root = new Node;
    root->word="";
    root->next = NULL;
    p = root;
    int m = strlen(a);
    For(i, 0, m-1){
        if (a[i] == ' '){
            p->next = new Node;
            p = p->next;
            p->word = "";
            p->next = NULL;
        }
        else{
            p->word += a[i];
        }
    }
    return root;
}


int main(){
    char a[100];
    char *b = NULL;

    cin.getline(a,256);
    //cout << a;
    b = chuanhoa(a);

    cout << b << endl;
    cout << nword << endl;

    Node *root = inds(b);
    while (root != NULL){
        cout<<root->word<<endl;
        root = root->next;
    }

    return 0;
}
