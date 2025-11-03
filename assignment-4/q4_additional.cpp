// The school cafeteria offers circular and square sandwiches at lunch break, referred to by
// numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or
// circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The
// sandwiches are placed in a stack. At each step:
// ●
// If the student at the front of the queue prefers the sandwich on the top of the stack, they
// will take it and leave the queue.
// ●
// Otherwise, they will leave it and go to the queue's end.
// This continues until none of the queue students want to take the top sandwich and are thus
// unable to eat
// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
// Output: 0

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    queue<int> q;
    for (int s : students)
        q.push(s);

    stack<int> st;

    for (int i = sandwiches.size() - 1; i >= 0; --i)
        st.push(sandwiches[i]);

    int rotations = 0;
    while (!q.empty() && !st.empty())
    {
        if (q.front() == st.top())
        {

            q.pop();
            st.pop();
            rotations = 0;
        }
        else
        {

            int x = q.front();
            q.pop();
            q.push(x);
            rotations++;
        }

        if (rotations == (int)q.size())
            break;
    }

    return q.size();
}

int main()
{
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    cout << countStudents(students, sandwiches) << '\n';
    return 0;
}
