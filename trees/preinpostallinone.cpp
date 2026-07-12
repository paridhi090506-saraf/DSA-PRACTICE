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

vector<vector<int>> preInPost(Node* root){
    stack<pair<Node*,int>> st;
    vector<int> pre,in,post;
    st.push({root,1});
    if(root==NULL)
    return {pre,in,post};
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }
        else
        post.push_back(it.first->data);
    }
    return {pre,in,post};
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    
    vector<vector<int>> ans=preInPost(root);
    for(auto it: ans[0]){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: ans[1]){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: ans[2]){
        cout<<it<<" ";
    }
    cout<<endl;
}