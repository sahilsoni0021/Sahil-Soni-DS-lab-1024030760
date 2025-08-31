// Given a string, reverse it using STACK. For example “DataStructure” should be output as
// “erutcurtSataD.”

#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverse(string s){
    stack<char> r;
    for (int i=0; i<s.size();i++){
        r.push(s[i]);
    }

    string rev = "";

    while(!r.empty()){
        rev = rev + r.top();
        r.pop();
    }
    return rev;
}

int main(){
    string st;
    getline(cin,st);

    st = reverse(st);
    cout << st << endl;
    return 0;
}