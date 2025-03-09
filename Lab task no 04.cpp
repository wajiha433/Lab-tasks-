#include <iostream> 
using namespace std; 
struct Node { 
int data; 
Node* next; 
}; 
void insertAtPosition(Node** head, int data, int position) { 
Node* newNode = new Node(); 
newNode->data = data; 
newNode->next = NULL; 
if (*head == NULL || position == 0) { 
newNode->next = *head; 
        *head = newNode; 
        return; 
    } 
    Node* current = *head; 
    for (int i = 0; i < position - 1 && current != NULL; i++) { 
        current = current->next; 
    } 
    if (current == NULL) { 
        cout << "Position out of range!" << endl; 
        delete newNode; 
        return; 
    } 
    newNode->next = current->next; 
    current->next = newNode; 
} 
void displayList(Node* head) { 
    Node* current = head; 
    while (current != NULL) { 
        cout << current->data << " -> "; 
        current = current->next; 
    } 
    cout << "NULL" << endl; 
} 
 
// Main function 
 
int main() { 
    Node* head = NULL; 
 
    insertAtPosition(&head, 10, 0); 
    insertAtPosition(&head, 20, 1); 
    insertAtPosition(&head, 30, 2); 
    insertAtPosition(&head, 40, 3); 
 
    cout << "Original Linked List: "; 
    displayList(head); 
 
    insertAtPosition(&head, 50, 4); 
    cout << "Linked List after inserting 50 at position 4: "; 
    displayList(head); 
 
    insertAtPosition(&head, 60, 10); 
    cout << "Linked List after inserting 60 at position 10: "; 
    displayList(head); 
 
    return 0; 
} 
 
