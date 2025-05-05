#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList() {
        front = rear = NULL; // Using NULL instead of nullptr
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
        } else {
            Node* temp = front;
            cout << "Dequeued: " << front->data << "\n";
            front = front->next;
            if (front == NULL) rear = NULL;
            delete temp;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
        } else {
            cout << "Queue elements: ";
            Node* temp = front;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    QueueLinkedList ql;

    cout << "\n--- Queue Using Linked List ---\n";
    ql.enqueue(100);
    ql.enqueue(200);
    ql.display();
    ql.dequeue();
    ql.display();

    return 0;
}
