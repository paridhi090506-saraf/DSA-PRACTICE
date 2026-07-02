#include<iostream>
#include<vector>
using namespace std;
void permute(vector<int> & arr,vector<int> & ds, vector<vector<int>> & ans, int freq[]){
    if(ds.size()==arr.size()){
    ans.push_back(ds);
    return;
    }
    for(int i=0;i<arr.size();i++){
        if(!freq[i]){
            ds.push_back(arr[i]);
            freq[i]=1;
            permute(arr,ds,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elemts of an array";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int freq[n]={0};
    vector<int> ds;
    vector<vector<int>> ans;
    permute(arr,ds,ans,freq);
    for(auto it:ans){
        for(auto ele:it)
        cout<<ele<<" ";
        cout<<endl;
    }
}