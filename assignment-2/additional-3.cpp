// 3) String Anagrams
// Given two strings str1 and str2, determine if they form an anagram pair.
// Note: Two strings are considered anagrams if one string can be rearranged to form the other
// string.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

   
    if (str1.length() != str2.length()) {
        cout << "Not Anagrams" << endl;
        return 0;
    }

    
    int freq1[26], freq2[26];

    
    for (int i = 0; i < 26; i++) {
        freq1[i] = 0;
        freq2[i] = 0;
    }

    
    for (int i = 0; i < str1.length(); i++) {
        char ch = str1[i];
        freq1[ch - 'a']++;
    }

    
    for (int i = 0; i < str2.length(); i++) {
        char ch = str2[i];
        freq2[ch - 'a']++;
    }

    
    bool isAnagram = true;
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            isAnagram = false;
            break;
        }
    }

    if (isAnagram)
        cout << "Anagrams" << endl;
    else
        cout << "Not Anagrams" << endl;

    return 0;
}
