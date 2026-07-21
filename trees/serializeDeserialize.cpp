#include<iostream>
#include<vector>
#include<queue>
#include <sstream>
#include<string>
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
string serialize(Node* root){
    string s;
    queue<Node*> q;
    if(root==NULL)
    return "";
    q.push(root);
    while(!q.empty()){
        Node* ele=q.front();
        q.pop();
        if(ele==NULL)
        s.append("#,");
        else
        s.append(to_string(ele->data)+",");
        if(ele!=NULL){
            q.push(ele->left);
            q.push(ele->right);
        }
    }
    return s;
}
Node* deserialize(string st){
    if(st.size()==0)
    return NULL;
    stringstream s(st);
    string str;
    getline(s,str,',');
    Node* root=new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* ele=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            ele->left=NULL;
        }
        else{
            Node* leftNode=new Node(stoi(str));
            ele->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#"){
            ele->right=NULL;
        }
        else{
            Node* rightNode=new Node(stoi(str));
            ele->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;
    Node* newRoot = deserialize(serialized);
    cout << "Level-order traversal after deserialization: ";
    queue<Node*> q;
    q.push(newRoot);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr == NULL) {
            cout << "# ";
            continue;
        }
        cout << curr->data << " ";
        q.push(curr->left);
        q.push(curr->right);
    }
    return 0;
}
