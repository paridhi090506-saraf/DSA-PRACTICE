#include<iostream>
#include<vector>
#include<queue>
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
vector<vector<int>> levelTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==NULL)
    return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            Node* ele=q.front();
            q.pop();
            if(ele->left!=NULL)
            q.push(ele->left);
            if(ele->right!=NULL)
            q.push(ele->right);
            level.push_back(ele->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    vector<vector<int>> ans;
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    ans=levelTraversal(root);
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
