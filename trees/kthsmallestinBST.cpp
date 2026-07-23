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

//ITERATIVE
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

//MORRIS
/*#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
int kthSmallest(Node* root, int k){
    int count = 0;
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            count++;
            if(count == k)
                return curr->data;
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                count++;
                if(count == k)
                    return curr->data;
                curr = curr->right;
            }
        }
    }
    return -1;   // k is greater than number of nodes
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    int k = 4;
    cout << "Kth Smallest = " << kthSmallest(root, k);
    return 0;
}*/