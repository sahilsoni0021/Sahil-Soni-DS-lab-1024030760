// 2) String Split Challenge
// You are given a string consisting of lowercase English alphabets. Your task is to determine if
// it's possible to split this string into three non-empty parts (substrings) where one of these
// parts is a substring of both remaining parts

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.length();
    bool found = false;

   
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            
            string part1 = "";
            for (int k = 0; k < i; k++) {
                part1 = part1 + s[k];
            }

            string part2 = "";
            for (int k = i; k < j; k++) {
                part2 = part2 + s[k];
            }

            string part3 = "";
            for (int k = j; k < n; k++) {
                part3 = part3 + s[k];
            }

            
            bool p1_in_p2 = false, p1_in_p3 = false;
            for (int a = 0; a <= part2.length() - part1.length(); a++) {
                bool match = true;
                for (int b = 0; b < part1.length(); b++) {
                    if (part2[a + b] != part1[b]) {
                        match = false;
                        break;
                    }
                }
                if (match) p1_in_p2 = true;
            }
            for (int a = 0; a <= part3.length() - part1.length(); a++) {
                bool match = true;
                for (int b = 0; b < part1.length(); b++) {
                    if (part3[a + b] != part1[b]) {
                        match = false;
                        break;
                    }
                }
                if (match) p1_in_p3 = true;
            }

            if (p1_in_p2 && p1_in_p3) {
                cout << "Split possible: [" << part1 << "] , [" << part2 << "] , [" << part3 << "]" << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found)
        cout << "YES, split is possible" << endl;
    else
        cout << "NO, split not possible" << endl;

    return 0;
}
