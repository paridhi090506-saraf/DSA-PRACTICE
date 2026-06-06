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
    if(arr.size()==0)
    return NULL;
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        temp->next= new Node(arr[i]);
        temp=temp->next;
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
Node* deleteHead(Node* head){
    if(head==NULL)
    return NULL;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* insertHead(Node* head,int val){
    if(head==NULL){
        head=new Node(val);
        return head;
    }
    Node* temp=new Node(val);
    temp->next=head;
    head=temp;
    return temp;
}
Node* deleteTail(Node* head){
    if(head==NULL||head->next==NULL){
    delete head;
    return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
Node* insertTail(Node* head, int val){
    if(head==NULL){
        head=new Node(val);
        return head;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    newNode->next=NULL;
    temp->next=newNode;
    return head;
}
Node* deleteKval(Node* head,int k){
    if(head==NULL)
    return NULL;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* insertKval(Node* head,int k, int val){
    if(k==1){
        Node* temp=new Node(val);
        temp->next=head;
        return temp;
    }
    int c=0;
    Node* temp=head;
    while(temp!=NULL){
        c++;
        if(c==(k-1)){
            Node* newnode=new Node(val);
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* deleteVal(Node* head, int val){
    if(head==NULL){
        return NULL;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==val)
        {
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main(){
    int n;
    cout<<"Enter the number of elements to be entered";
    cin>>n;
    vector<int> arr;
    int d;
    for(int i=0;i<n;i++){
        cin>>d;
        arr.push_back(d);
    }
    Node* head= convertToLL(arr);
    print(head);
    head=deleteHead(head);
    print(head);
    head=insertHead(head,1);
    print(head);
    head=deleteTail(head);
    print(head);
    head=insertTail(head,5);
    print(head);
    head=deleteKval(head,3);
    print(head);
    head=insertKval(head,3,3);
    print(head);
    head=deleteVal(head,3);
    print(head);
}