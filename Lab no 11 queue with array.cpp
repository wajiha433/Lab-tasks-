#include <iostream>
using namespace std;

const int SIZE = 100; // Replaces #define

class QueueArray {
private:
    int arr[SIZE];
    int front, rear;

public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
        } else {
            cout << "Dequeued: " << arr[front++] << "\n";
            if (front > rear) {
                front = rear = -1; // Reset queue
            }
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    QueueArray qa;

    cout << "--- Queue Using Array ---\n";
    qa.enqueue(10);
    qa.enqueue(20);
    qa.display();
    qa.dequeue();
    qa.display();

    return 0;
}
