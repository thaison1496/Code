/** \author: son14020800
    \brief: chuong trinh quan li sinh vien
*/
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

#define For(i, a, b) for(int i = a; i <= b; i++)

typedef struct Node{
    string lname; //ho va ten dem
    string fname; //ten
    double score; //diem so
    Node* next;
    Node* pre;
};
/** \brief : nhap ds lien ket
    \return con tro dau ds
*/
Node* nhapds(){
    Node* root;
    Node* p;
    root = new Node;
    root->next = NULL;
    p = root;
    int ct = 0;
    while (true){
        ct ++ ;
        cout << "Sinh vien thu " << ct << ":" << endl;
        cout << "Nhap ho va ten dem (nhap exit de thoat): ";
        cin >> p->lname;
        if (p->lname == "exit"){
            p->next = NULL;
            break;
        }
        cout << "Nhap ten: ";
        cin >> p->fname;
        cout << "Nhap diem: ";
        cin >> p->score;
        p->next = new Node;
        p = p->next;
    }
    return root;
}

/** \brief in danh sach
    \param root: node dau ds
*/
int inds(Node* root){
    Node* p;
    p = root;
    int ct = 0;
    while (true){
        if (p->next == NULL) break;
        ct ++ ;
        cout << "Sinh vien thu " << ct << ":" << endl;
        cout << "Ho ten: " << p->lname << " " << p->fname << endl;
        cout << "Diem: ";
        printf("%0.2f\n",p->score);
        p = p->next;
    }
    return 0;
}
/** \brief so sanh 2 node p q theo diem hoac ten
    \param p node thu 1
    \param q node thu 2
    \param k k=0 so sanh theo diem; k=1 so sanh theo ten
    \return true neu node p > node q
*/
bool lonhon(Node* p, Node* q, int k){
    if (k==0){
        if (p->score > q->score) return true;
        else return false;
    }
    if (k==1){
        if (p->fname > q->fname) return true;
        else return false;
    }
}

/** \brief doi cho 2 node p q
*/
int doicho(Node* p, Node* q){

    return 0;
}

/** \brief sap xep danh sach
    \param root : node dau danh sach
    \param k : k=0: sap xep theo diem;
               k=1: sap xep theo ten
*/
int sapxep(Node* root, int k){
    Node* p = root;
    while (p->next->next != NULL){
        Node* q;
        q = p->next;
        while (q->next != NULL){
            if lonhon(p,q,k)
                doicho(p,q);
        }
    }

    return 0;
}
int main(){
    Node* root;
    root = nhapds();
    cout << endl << "In danh sach: " << endl;
    inds(root);
    sapxep(root,0);
    cout << endl << "Danh sach sap xep theo diem: " << endl;
    inds(root);
    sapxep(root,1);
    cout << endl << "Danh sach sap xep theo ten: " << endl;
    inds(root);

    return 0;
}
