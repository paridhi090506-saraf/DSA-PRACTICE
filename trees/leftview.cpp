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
void left(Node* root,int level,vector<int> & ans){
    
    if(root==NULL)
    return ;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    left(root->left,level+1,ans);
    left(root->right,level+1,ans);
    

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
    vector<int> ans;
    left(root,0,ans);
    for(auto it:ans)
    cout<<it<<" ";
    
}