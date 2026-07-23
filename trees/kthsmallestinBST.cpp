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
void inorder(Node* root, int &count, int k, int &ans){
    if(root==NULL || count>=k)
        return;
    inorder(root->left, count, k, ans);
    count++;
    if(count==k){
        ans=root->data;
        return;
    }
    inorder(root->right, count, k, ans);
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    int k=4;
    int count=0;
    int ans=-1;
    inorder(root, count, k, ans);
    cout << "Kth Smallest = " << ans;
    return 0;
}


/*#include<iostream>
#include<stack>
using namespace std;
int kthSmallest(Node* root, int k){
    stack<Node*> st;
    while(true){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        k--;
        if(k==0)
            return root->data;
        root=root->right;
    }
}*/