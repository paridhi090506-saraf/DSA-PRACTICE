#include<iostream>
#include<vector>
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
    Node(int data1,Node* next1, Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
};
Node* convertToDLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newnode=new Node(arr[i]);
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;

    }
    return head;

}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}
Node* reverseDLL(Node* head){
    Node* current=head;
    Node* back=nullptr;
    while(current!=NULL){
        back=current->prev;
        current->prev=current->next;
        current->next=back;
        current=current->prev;
    }
    head=back->prev;
    return head;
}
int main(){
    int n;
    cout<<"Enter the number of elements to be inserted:";
    cin>>n;
    int d;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>d;
        arr.push_back(d);
        
    }
    Node* head=convertToDLL(arr);
    print(head);
    head=reverseDLL(head);
    print(head);
}