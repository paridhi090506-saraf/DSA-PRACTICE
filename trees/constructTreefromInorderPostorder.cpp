#include<iostream>
#include<vector>
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
Node* treeBuilding(vector<int> & postorder, int postStart, int postEnd, vector<int> & inorder, int inStart, int inEnd, map<int,int> inMap){
    if(postStart>postEnd || inStart>inEnd)
    return NULL;
    Node* root= new Node(postorder[postEnd]);
    int inRoot=inMap[root->data];
    int numsLeft=inRoot-inStart;
    root->left=treeBuilding(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,inMap);
    root->right=treeBuilding(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,inMap);
    return root;
}
Node* buildTree(vector<int> & postorder, vector<int> & inorder){
    map<int,int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]]=i;
    }
    Node* root=treeBuilding(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main(){
    vector<int> inorder={40,20,50,10,60,30};
    vector<int> postorder={40,50,20,60,30,10};
    Node* root=buildTree(postorder,inorder);
    inorderTraversal(root);
}