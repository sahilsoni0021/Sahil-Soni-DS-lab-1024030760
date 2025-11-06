// Implement priority queues using heaps.

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < heap.size() && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(40);

    cout << "Priority Queue (Max-Heap): ";
    pq.display();

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "After removing top element: ";
    pq.display();
}
