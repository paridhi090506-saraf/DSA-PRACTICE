#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Convert array to linked list
Node* convertToLL(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at beginning
Node* insert_begin(Node* head, int data) {
    Node* newnode = new Node(data);
    newnode->next = head;
    return newnode;
}

// Insert at end
Node* insert_end(Node* head, int data) {
    Node* newnode = new Node(data);

    if (head == NULL) return newnode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;

    return head;
}

// Insert at position (0-based index)
Node* insert_at_pos(Node* head, int data, int pos) {
    Node* newnode = new Node(data);

    if (pos == 0) {
        newnode->next = head;
        return newnode;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return head;

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

// Delete beginning
Node* delete_begin(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

// Delete end
Node* delete_end(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    return head;
}

// Delete at position (0-based)
Node* delete_at_pos(Node* head, int pos) {
    if (head == NULL) return NULL;

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return head;

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

// Delete by value
Node* delete_value(Node* head, int k) {
    if (head == NULL) return NULL;

    if (head->data == k) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != k) {
        temp = temp->next;
    }

    if (temp->next == NULL) return head;

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

// MAIN FUNCTION
int main() {
    vector<int> arr = {1, 2, 3, 4};

    Node* head = convertToLL(arr);

    cout << "Initial List: ";
    print(head);

    head = insert_begin(head, 0);
    cout << "After insert at beginning: ";
    print(head);

    head = insert_end(head, 5);
    cout << "After insert at end: ";
    print(head);

    head = insert_at_pos(head, 99, 3);
    cout << "After insert at position 3: ";
    print(head);

    head = delete_begin(head);
    cout << "After delete beginning: ";
    print(head);

    head = delete_end(head);
    cout << "After delete end: ";
    print(head);

    head = delete_at_pos(head, 2);
    cout << "After delete at position 2: ";
    print(head);

    head = delete_value(head, 99);
    cout << "After delete value 99: ";
    print(head);

    return 0;
}