#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = NULL; // Replaced nullptr with NULL
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
        } else {
            cout << "Popped: " << top->data << "\n";
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
        } else {
            cout << "Stack elements: ";
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    StackLinkedList sl;

    cout << "\n--- Stack Using Linked List ---\n";
    sl.push(100);
    sl.push(200);
    sl.display();
    sl.pop();
    sl.display();

    return 0;
}
