#include<iostream>
using namespace std;

struct Element {
    int i, j, x;
};

struct Sparse {
    int m, n, num;
    Element *ele;
};

void create(Sparse *s) {
    cout<<"Enter dimensions: ";
    cin>>s->m>>s->n;
    cout<<"Number of non-zero elements: ";
    cin>>s->num;
    s->ele=new Element[s->num];

    cout<<"Enter row col value:\n";
    for(int k=0;k<s->num;k++)
        cin>>s->ele[k].i>>s->ele[k].j>>s->ele[k].x;
}

void display(Sparse s) {
    int k=0;
    for(int i=0;i<s.m;i++) {
        for(int j=0;j<s.n;j++) {
            if(k<s.num && s.ele[k].i==i && s.ele[k].j==j)
                cout<<s.ele[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

Sparse transpose(Sparse s) {
    Sparse t;
    t.m = s.n;
    t.n = s.m;
    t.num = s.num;
    t.ele = new Element[t.num];
    for(int k=0;k<s.num;k++) {
        t.ele[k].i = s.ele[k].j;
        t.ele[k].j = s.ele[k].i;
        t.ele[k].x = s.ele[k].x;
    }
    return t;
}
