// Write a program that checks if an expression has balanced parentheses.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (st.empty()) return false;

            if (s[i] == ')') {
                if (st.top() != '(') return false;
                else st.pop();
            }
            else if (s[i] == '}') {
                if (st.top() != '{') return false;
                else st.pop();
            }
            else if (s[i] == ']') {
                if (st.top() != '[') return false;
                else st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;  

    if (isValid(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
