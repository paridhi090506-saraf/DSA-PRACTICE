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
Node* sort(Node* head){
    if(head==NULL||head->next==NULL)
    return head;
    Node* dummyZero=new Node(-1);
    Node* zero=dummyZero;
    Node* dummyOne=new Node(-1);
    Node* one=dummyOne;
    Node* dummyTwo=new Node(-1);
    Node* two=dummyTwo;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
        zero->next=temp;
        zero=zero->next;
        temp=temp->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
            temp=temp->next;
        }
        else{
            two->next=temp;
            two=two->next;
            temp=temp->next;
        }
    }
        zero->next=dummyOne->next?dummyOne->next:dummyTwo->next;
        one->next=dummyTwo->next;
        two->next=NULL;
        Node* newHead=dummyZero->next;
        delete dummyZero;
        delete dummyOne;
        delete dummyTwo;
        return newHead;
}
int main(){
    vector<int> arr={0,1,2,0,0,1,1,2,1};
    Node* head=convertToLL(arr);
    head=sort(head);
    print(head);
}