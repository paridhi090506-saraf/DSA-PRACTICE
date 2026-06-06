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
Node* reverse(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* after=temp->next;
        temp->next=prev;
        prev=temp;
        temp=after;
    }
    return prev;
}
bool palin(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newhead=reverse(slow->next);
    Node* second=newhead;
    Node* first=head;
    while(second!=NULL){
    if(first->data!=second->data){
        slow->next=reverse(newhead);
    return false;
    }
    first=first->next;
    second=second->next;
}
    slow->next=reverse(newhead);
    return true;
}
int main(){
    vector<int> arr={1,1,2,1};
    Node* head=convertToLL(arr);
    print(head);
    cout<<palin(head);
}