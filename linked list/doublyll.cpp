#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

    Node(int data1, Node* next1, Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
};

// Convert array to Doubly Linked List
Node* convertToDLL(vector<int> &arr){
    if(arr.size()==0)
        return NULL;

    Node* head=new Node(arr[0]);
    Node* temp=head;

    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);

        temp->next=newNode;
        newNode->prev=temp;

        temp=newNode;
    }

    return head;
}

// Print DLL
void print(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

// Delete Head
Node* deleteHead(Node* head){
    if(head==NULL)
        return NULL;

    if(head->next==NULL){
        delete head;
        return NULL;
    }

    Node* temp=head;

    head=head->next;
    head->prev=NULL;

    delete temp;

    return head;
}

// Insert at Head
Node* insertHead(Node* head, int val){
    Node* newNode=new Node(val);

    if(head==NULL)
        return newNode;

    newNode->next=head;
    head->prev=newNode;

    return newNode;
}

// Delete Tail
Node* deleteTail(Node* head){
    if(head==NULL)
        return NULL;

    if(head->next==NULL){
        delete head;
        return NULL;
    }

    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->prev->next=NULL;

    delete temp;

    return head;
}

// Insert at Tail
Node* insertTail(Node* head, int val){
    Node* newNode=new Node(val);

    if(head==NULL)
        return newNode;

    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;

    return head;
}

// Delete Kth Node
Node* deleteKval(Node* head, int k){
    if(head==NULL)
        return NULL;

    if(k==1)
        return deleteHead(head);

    int count=0;
    Node* temp=head;

    while(temp!=NULL){
        count++;

        if(count==k){

            if(temp->next==NULL){
                temp->prev->next=NULL;
                delete temp;
                break;
            }

            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;

            delete temp;
            break;
        }

        temp=temp->next;
    }

    return head;
}

// Insert at Kth Position
Node* insertKval(Node* head, int k, int val){

    if(k==1)
        return insertHead(head, val);

    int count=0;
    Node* temp=head;

    while(temp!=NULL){
        count++;

        if(count==(k-1)){

            // insert at tail
            if(temp->next==NULL){
                Node* newNode=new Node(val);

                temp->next=newNode;
                newNode->prev=temp;

                break;
            }

            Node* front=temp->next;

            Node* newNode=new Node(val);

            temp->next=newNode;
            newNode->prev=temp;

            newNode->next=front;
            front->prev=newNode;

            break;
        }

        temp=temp->next;
    }

    return head;
}

// Delete Node by Value
Node* deleteVal(Node* head, int val){

    if(head==NULL)
        return NULL;

    Node* temp=head;

    while(temp!=NULL){

        if(temp->data==val){

            // head node
            if(temp==head){
                return deleteHead(head);
            }

            // tail node
            if(temp->next==NULL){
                temp->prev->next=NULL;
                delete temp;
                return head;
            }

            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;

            delete temp;

            break;
        }

        temp=temp->next;
    }

    return head;
}

int main(){

    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr;

    int d;

    for(int i=0;i<n;i++){
        cin>>d;
        arr.push_back(d);
    }

    Node* head=convertToDLL(arr);

    cout<<"Original DLL: ";
    print(head);

    head=deleteHead(head);
    cout<<"After deleting head: ";
    print(head);

    head=insertHead(head,1);
    cout<<"After inserting 1 at head: ";
    print(head);

    head=deleteTail(head);
    cout<<"After deleting tail: ";
    print(head);

    head=insertTail(head,5);
    cout<<"After inserting 5 at tail: ";
    print(head);

    head=deleteKval(head,3);
    cout<<"After deleting 3rd node: ";
    print(head);

    head=insertKval(head,3,3);
    cout<<"After inserting 3 at 3rd position: ";
    print(head);

    head=deleteVal(head,3);
    cout<<"After deleting value 3: ";
    print(head);

    return 0;
}