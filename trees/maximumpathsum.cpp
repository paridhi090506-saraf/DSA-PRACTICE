#include<iostream>
#include<climits>
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
int maxPath(Node* root,int & maxi){
    if(root==NULL)
    return 0;
    int lh=max(0,maxPath(root->left,maxi));
    int rh=max(0,maxPath(root->right,maxi));
    maxi=max(maxi,root->data+lh+rh);
    return root->data+max(lh,rh);
}
int maxPathSum(Node* root){
    int maxi=INT_MIN;
    maxPath(root,maxi);
    return maxi;
}
int main(){
    Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);

    int ans=maxPathSum(root);
    cout<<ans<<endl;
}