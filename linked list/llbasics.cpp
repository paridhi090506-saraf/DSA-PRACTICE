#include<bits/stdc++.h>
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
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int lengthofLL(Node* head){
    Node* temp=head;
    int count=0;
    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }
    return count;
}
void search(Node* head,int val){
    Node* temp=head;
    int flag=0;
    while(temp!=nullptr){
        if(temp->data==val){
        flag=1;
        break;
        }
        temp=temp->next;
    }
    if(flag==1)
    cout<<"Found";
    else
    cout<<"Not found";
}
int main(){
    int n;
    cout<<"Enter the number of data to be inserted";
    cin>>n;
    int d;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>d;
        arr.push_back(d);
    }
    Node* head=convertToLL(arr);
    print(head);
    int l=lengthofLL(head);
    cout<<"Length of LL is "<<l<<endl;
    search(head,8);
    return 0;
}