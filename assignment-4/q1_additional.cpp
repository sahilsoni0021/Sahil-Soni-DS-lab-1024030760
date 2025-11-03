//  Given a function n, write a function that generates and prints all binary numbers with decimal
// values from 1 to n.
// Input: n = 2
// Output: 1, 10

#include <iostream>
#include <queue>
using namespace std;

vector<string> generateBinary(int n)
{
    vector<string> res;
    queue<string> q;

    q.push("1");

    while (n--)
    {

        string s1 = q.front();
        q.pop();
        res.push_back(s1);

        string s2 = s1;

        if (q.size() < n)
        {

            q.push(s1.append("0"));

            q.push(s2.append("1"));
        }
    }
    return res;
}

int main()
{
    int n = 6;

    vector<string> res = generateBinary(n);

    for (auto i : res)
    {
        cout << i << " ";
    }

    cout << "\n";
    return 0;
}