#include<iostream>
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
int floorFind(Node* root,int key){
    int floor=-1;
    while(root){
        if(key==root->data){
            floor=root->data;
            return floor;
        }
        else if(key>root->data){
            floor=root->data;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return floor;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->left->left=new Node(3);
    root->left->left->left=new Node(2);
    root->left->right=new Node(6);
    root->left->left->right=new Node(4);
    root->left->right->right=new Node(9);
    root->right=new Node(13);
    root->right->left=new Node(11);
    root->right->right=new Node(14);

    int ans=floorFind(root,8);
    cout<<ans;
}