#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = NULL;
    }
};

int main() {
    //  Object creation (stack)
    Node obj = Node(20);

    //  Pointer creation (heap)
    Node* ptr = new Node(30);

    // Access object
    cout << "Object data: " << obj.data << endl;
    cout << "Object next: " << obj.next << endl;

    // Access pointer object
    cout << "Pointer data: " << ptr->data << endl;
    cout << "Pointer next: " << ptr->next << endl;

    return 0;
}