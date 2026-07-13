#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};
bool isIdentical(Node* p,Node* q){
    if(p==NULL || q==NULL)
    return (p==q);
    return (p->data == q->data) && isIdentical(p->left,q->left) && isIdentical(p->right,q->right);
}
int main(){
    Node* root1=new Node(10);
    root1->left=new Node(20);
    root1->right=new Node(30);
    root1->left->left=new Node(40);
    root1->left->right=new Node(50);
    
    Node* root2=new Node(10);
    root2->left=new Node(20);
    root2->right=new Node(30);
    root2->left->left=new Node(40);
    root2->left->right=new Node(50);
    root2->left->right->left=new Node(60);

    bool ans=isIdentical(root1,root2);
    cout<<ans;
}