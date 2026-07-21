#include<iostream>
#include<vector>
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
vector<int> preorderTrav(Node* root){
    vector<int> preorder;
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right &&  prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                preorder.push_back(curr->data);
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preorder;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->right=new Node(6);
    root->right=new Node(3);

    vector<int> preorder=preorderTrav(root);
    for(auto it: preorder){
        cout<<it<<" ";
    }
}