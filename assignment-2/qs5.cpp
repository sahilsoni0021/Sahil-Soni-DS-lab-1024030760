#include<iostream>
using namespace std;

class DiagonalMatrix {
    int *A, n;
public:
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i,int j,int x) {
        if(i==j) A[i-1] = x;
    }
    int get(int i,int j) {
        if(i==j) return A[i-1];
        else return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j) cout<<A[i-1]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

class LowerTriangular {
    int *A, n;
public:
    LowerTriangular(int n) {
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void set(int i,int j,int x) {
        if(i>=j) A[i*(i-1)/2 + j-1] = x;
    }
    int get(int i,int j) {
        if(i>=j) return A[i*(i-1)/2 + j-1];
        else return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i>=j) cout<<A[i*(i-1)/2+j-1]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

class UpperTriangular {
    int *A, n;
public:
    UpperTriangular(int n) {
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void set(int i,int j,int x) {
        if(i<=j) A[n*(i-1) - (i-2)*(i-1)/2 + j-i] = x;
    }
    int get(int i,int j) {
        if(i<=j) return A[n*(i-1) - (i-2)*(i-1)/2 + j-i];
        else return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i<=j) cout<<get(i,j)<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};


int main() {
    int n = 3;

    DiagonalMatrix d(n);
    d.set(1, 1, 5);
    d.set(2, 2, 8);
    d.set(3, 3, 6);
    cout << "Diagonal Matrix:" << endl;
    d.display();

    LowerTriangular l(n);
    l.set(1, 1, 1);
    l.set(2, 1, 2);
    l.set(2, 2, 3);
    l.set(3, 1, 4);
    l.set(3, 2, 5);
    l.set(3, 3, 6);
    cout << "\nLower Triangular Matrix:" << endl;
    l.display();

    UpperTriangular u(n);
    u.set(1, 1, 7);
    u.set(1, 2, 8);
    u.set(1, 3, 9);
    u.set(2, 2, 10);
    u.set(2, 3, 11);
    u.set(3, 3, 12);
    cout << "\nUpper Triangular Matrix:" << endl;
    u.display();

    return 0;
}
