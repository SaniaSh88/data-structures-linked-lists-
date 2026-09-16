#include <iostream>
using namespace std;

// 1. Defining the Structure of a Node
struct Node {
    int data;     // The actual value stored in the node
    Node* next;   // Pointer to the next node in the sequence

    // Constructor to make creating nodes easier
    Node(int val) {
        data = val;
        next = nullptr; // By default, a new node points to nothing
    }
};

// 2. The Linked List Class managing the operations
class LinkedList {
private:
    Node* head; // Pointer to the very first node

public:
    // Constructor initializes an empty list
    LinkedList() {
        head = nullptr;
    }

    // --- OPERATION 1: INSERTION (At the Beginning) ---
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val); // Allocate memory for the new node
        newNode->next = head;          // Point new node's next to the current head
        head = newNode;                // Update head to be the new node
        cout << "Inserted " << val << " at the beginning.\n";
    }

    // --- OPERATION 2: TRAVERSAL ---
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head; // Start from the head
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next; // Move to the next node
        }
        cout << "NULL\n"; // End of the list
    }

    // --- OPERATION 3: DELETION (By Value) ---
    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        // Case 1: The node to be deleted is the head node
        if (temp != nullptr && temp->data == key) {
            head = temp->next; // Change head to the second node
            delete temp;       // Free the memory of the old head
            cout << "Deleted " << key << " from the list.\n";
            return;
        }

        // Case 2: Search for the key to be deleted, keeping track of the prev node
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // Case 3: If the key was not found in the list
        if (temp == nullptr) {
            cout << "Value " << key << " not found in the list.\n";
            return;
        }

        // Case 4: Unlink the node from the list and free memory
        prev->next = temp->next; // Skip over the node to be deleted
        delete temp;             // Free up the memory
        cout << "Deleted " << key << " from the list.\n";
    }
};

// 3. Driver Code to test the operations
int main() {
    LinkedList list;

    // Test Insertion
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    // Test Traversal
    cout << "Current Linked List: ";
    list.traverse();

    // Test Deletion
    list.deleteNode(20); // Deleting a middle node
    cout << "After deleting 20: ";
    list.traverse();

    list.deleteNode(10); // Deleting the head node
    cout << "After deleting 10: ";
    list.traverse();

    return 0;
}
