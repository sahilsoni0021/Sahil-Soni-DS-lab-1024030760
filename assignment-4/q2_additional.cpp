// Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The
// operations allowed on queue are:
// 1. enqueue() : Adds an item to rear of queue.
// 2. dequeue() : Removes an item from front of queue.
// 3. isEmpty() : Checks if a queue is empty.
// Input: 11, 5, 4, 21
// Output: 4, 5, 11, 21

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int findMinIndex(queue<int> &q, int limit)
{
    int n = q.size();
    int min_index = -1;
    int min_val = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();

        if (i <= limit && curr < min_val)
        {
            min_val = curr;
            min_index = i;
        }

        q.push(curr); // put it back
    }
    return min_index;
}

void moveMinToRear(queue<int> &q, int min_index)
{
    int n = q.size();
    int min_val = 0;

    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();

        if (i == min_index)
        {
            min_val = curr; // found the min
        }
        else
        {
            q.push(curr);
        }
    }
    q.push(min_val); // put min at end
}

void sortQueue(queue<int> &q)
{
    int n = q.size();

    for (int i = 1; i <= n; i++)
    {
        int min_index = findMinIndex(q, n - i);
        moveMinToRear(q, min_index);
    }
}

void display(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
        if (!q.empty())
            cout << ", ";
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    cout << "Original Queue: ";
    display(q);

    sortQueue(q);

    cout << "Sorted Queue: ";
    display(q);

    return 0;
}
