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
vector<vector<int>> zigzag(Node* root){
    queue<Node*> q;
    vector<vector<int>> ans;
    if(root==NULL)
    return ans;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int n=q.size();
        vector<int> level(n);
        for(int i=0;i<n;i++){
            Node* ele=q.front();
            q.pop();
            int index=leftToRight?i:n-1-i;
            level[index]=ele->data;
            if(ele->left){
                q.push(ele->left);
            }
            if(ele->right){
                q.push(ele->right);
            }
        }
        leftToRight=!leftToRight;
        ans.push_back(level);
    }
    return ans;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);

    vector<vector<int>> ans=zigzag(root);
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}