#include<iostream>
#include<vector>
using namespace std;
void permute(int ind,vector<int> & arr, vector<vector<int>> & ans){
    if(ind==arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=ind;i<arr.size();i++){
        swap(arr[i],arr[ind]);
        permute(ind+1,arr,ans);
        swap(arr[i],arr[ind]);
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
    vector<vector<int>> ans;
    permute(0,arr,ans);
    for(auto it:ans){
        for(auto ele:it)
        cout<<ele<<" ";
        cout<<endl;
    }
}


/*#include<iostream>
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
}*/