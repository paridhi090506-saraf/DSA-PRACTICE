#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
vector<int> bottom(Node* root){
    queue<pair<Node*,int>> q;
    vector<int> ans;
    if(root==NULL)
    return ans;
    map<int,int> mpp;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node* ele=it.first;
        int line=it.second;
        mpp[line]=ele->data;
        if(ele->left!=NULL)
        q.push({ele->left,line-1});
        if(ele->right!=NULL)
        q.push({ele->right,line+1});

    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<int> ans=bottom(root);
    for(auto it:ans)
    cout<<it<<" ";
    
}