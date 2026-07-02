#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void subsetSum(vector<int> & arr,int ind, vector<int> & ds, vector<vector<int>> & ans){
    ans.push_back(ds);
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1])
        continue;
        ds.push_back(arr[i]);
        subsetSum(arr,i+1,ds,ans);
        ds.pop_back();
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements of an array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elemnts of an array";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr.begin(),arr.end());
    vector<int> ds;
    vector<vector<int>> ans;
    subsetSum(arr,0,ds,ans);
    for(auto it:ans){
        for(auto ele:it)
        cout<<ele<<" ";
        cout<<endl;
    }
}
