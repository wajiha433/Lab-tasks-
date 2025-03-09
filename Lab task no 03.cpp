 #include <iostream> 
    using namespace std; 
     
    struct Node { 
        int data; 
        Node* next; 
    }; 
     
    Node* head = NULL; 
     
    void insertAtStart(int data) { 
        Node* newNode = new Node(); 
        newNode->data = data; 
        newNode->next = head; 
        head = newNode; 
        cout << "Node inserted at start: " << data << endl; 
    } 
     
    void insertAtEnd(int data) { 
        Node* newNode = new Node(); 
        newNode->data = data; 
        newNode->next = NULL; 
         
        if (head == NULL) { 
            head = newNode; 
            cout << "Node inserted at end: " << data << endl; 
            return; 
        } 
         
        Node* temp = head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
        cout << "Node inserted at end: " << data << endl; 
    } 
     
    void displayList() { 
        Node* temp = head; 
        cout << "List: "; 
        while (temp != NULL) { 
            cout << temp->data << " -> "; 
            temp = temp->next; 
        } 
        cout << "NULL" << endl; 
    } 
     
    int main() { 
        insertAtStart(5); 
        displayList(); 
         
        insertAtStart(3); 
        displayList(); 
         
        insertAtEnd(7); 
        displayList(); 
         
        insertAtEnd(10); 
        displayList(); 
         
        return 0; 
    }
