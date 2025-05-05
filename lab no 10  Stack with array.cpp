#include <iostream>
using namespace std;

const int STACK_SIZE = 100; // Replaces #define SIZE 100

class StackArray {
private:
    int arr[STACK_SIZE];
    int top;

public:
    StackArray() {
        top = -1;
    }

    void push(int value) {
        if (top >= STACK_SIZE - 1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = value;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
        } else {
            cout << "Popped: " << arr[top--] << "\n";
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    StackArray sa;

    cout << "--- Stack Using Array ---\n";
    sa.push(10);
    sa.push(20);
    sa.display();
    sa.pop();
    sa.display();

    return 0;
}
