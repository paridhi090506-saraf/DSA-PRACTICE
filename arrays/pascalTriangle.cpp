#include<iostream>
#include<vector>
using namespace std;
int nCr(int n,int r){
    int ans=1;
    for(int i=0;i<r;i++){
        ans=ans*(n-i);
        ans=ans/(i+1);
    }
    return ans;
}
vector<int> GenerateRow(int n){//n is row
    vector<int> ans;
    ans.push_back(1);
    long long t=1;
    for(int i=1;i<n;i++){//i is column
        t=t*(n-i);
        t=t/i;
        ans.push_back(t);

    }
    return ans;
}
int main(){
    int r;
    int c;
    cout<<"Enter the value of row and column"<<endl;
    cin>>r;
    cin>>c;
    cout<<nCr(r-1,c-1)<<endl;
    cout<<"The full row is"<<endl;
    vector<int> row=GenerateRow(r);
    for(auto it:row)
    cout<<it<<" ";
    cout<<endl;
    vector<vector<int>> triangle;
    for(int i=1;i<=r;i++){
        triangle.push_back(GenerateRow(i));
    }
    for(auto it: triangle){
        for(auto ele:it){
        cout<<ele<<" ";
        }
        cout<<endl;
    }
}