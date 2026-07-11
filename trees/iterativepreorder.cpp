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
vector<int> preordertraversal(Node* root){
    stack<Node*> st;
    vector<int> ans;
    if(root==NULL)
    return ans;
    st.push(root);
    while(!st.empty()){
        Node* ele=st.top();
        st.pop();
        ans.push_back(ele->data);
        if(ele->right!=NULL)
        st.push(ele->right);
        if(ele->left!=NULL)
        st.push(ele->left);
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
    ans=preordertraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
}