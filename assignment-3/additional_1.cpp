// Given an array A, find the nearest smaller element for every element A[i] in the array such that
// the element has an index smaller than i.

// nearest smaller element in left 

#include<iostream>
using namespace std;

int main(){
    int arr[5] = {4,5,2,10,8};
    int n = 5;

    stack<int> st;
    vector<int> v;

    for (int i=0; i<n; i++){

        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }

        if (st.empty()){
            v.push_back(-1);
        }
        else{
            v.push_back(st.top());
        }

        st.push(arr[i]);
    }

    for (int i=0; i<n; i++){
        cout << v[i] << " " ;
    }
    return 0;
}