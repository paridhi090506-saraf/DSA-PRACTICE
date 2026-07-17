#include<iostream>
#include<queue>
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
int maxWidth(Node* root){
    if(root==NULL)
    return 0;
    queue<pair<Node*,int>> q;
    int ans=0;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int min=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
        int curID=q.front().second-min;
        Node* ele=q.front().first;
        q.pop();
        if(i==0)
        first=curID;
        if(i==size-1)
        last=curID;
        if(ele->left!=NULL)
        q.push({ele->left,curID*2+1});
        if(ele->right!=NULL)
        q.push({ele->right,curID*2+2});
        }
        ans=max(ans,last-first+1);
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
    int ans=maxWidth(root);
    cout<<ans<<endl;
}