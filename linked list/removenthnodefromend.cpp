#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
};
Node* convertToLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}
Node*removefromend(Node* head,int n){
    if(head==NULL)
    return NULL;
    if(head==NULL && n==1)
    return head;
    Node* fast=head;
    Node* slow=head;
    for(int i=0;i<n;i++)
    fast=fast->next;
    if(fast==NULL){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node* temp= slow->next;
    
    slow->next=slow->next->next;
    delete temp;
    return head;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertToLL(arr);
    head=removefromend(head,2);
    print(head);
}