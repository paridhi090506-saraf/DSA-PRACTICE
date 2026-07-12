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

vector<int> postordertraversal(Node* root){
    vector<int> ans;
    stack<Node*> st;
    Node* curr=root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
        st.push(curr);
        curr=curr->left;
        }
        else{
            Node* temp=st.top()->right;
            if(temp==NULL){
            temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            while(!st.empty() && temp==st.top()->right){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
            }
            }
            else
            curr=temp;

        }
    }
    return ans;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    
    vector<int> ans=postordertraversal(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
}