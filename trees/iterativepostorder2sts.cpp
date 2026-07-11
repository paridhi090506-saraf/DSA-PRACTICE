#include<iostream>
#include<vector>
#include<stack>
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
vector<int> postordertraversal(Node* root){
    stack<Node*> st1,st2;
    vector<int> ans;
    st1.push(root);
    if(root==NULL){
        return ans;
    }
    while(!st1.empty()){
        Node* ele=st1.top();
        st1.pop();
        st2.push(ele);
        if(ele->left!=NULL)
        st1.push(ele->left);
        if(ele->right!=NULL)
        st1.push(ele->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    vector<int> ans;
    ans=postordertraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
}