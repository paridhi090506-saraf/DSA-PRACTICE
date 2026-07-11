#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
vector<int> inordertraversal(Node* root){
     stack<Node*> st;
     vector<int> ans;
     Node* ele=root;
     while(true){
        if(ele!=nullptr){
            st.push(ele);
            ele=ele->left;
        }
        else{
            if(st.empty())
            break;
            ele=st.top();
            st.pop();
            ans.push_back(ele->data);
            ele=ele->right;
        }
     }
     return ans;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    
    vector<int> ans=inordertraversal(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
}