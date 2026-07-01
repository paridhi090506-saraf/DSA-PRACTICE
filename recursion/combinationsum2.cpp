#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void combi(int ind, vector<int> & arr, int target, vector<vector<int>> & ans, vector<int> & ds){
     if(target==0){
        ans.push_back(ds);
        return;
     }
     for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1])
        continue;
        if(arr[i]>target)
        break;
        ds.push_back(arr[i]);
        combi(i+1,arr,target-arr[i],ans,ds);
        ds.pop_back();
     }
}
int main(){
    int n;
    cout<<"Enter the number of elements in array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr.begin(),arr.end());
    int target;
    cout<<"Enter the target";
    cin>>target;
    vector<int> ds;
    vector<vector<int>> ans;
    combi(0,arr,target,ans,ds);
    for(auto it:ans){
        for(auto ele:it)
        cout<<ele<<" ";
        cout<<endl;
    }
    return 0;
}