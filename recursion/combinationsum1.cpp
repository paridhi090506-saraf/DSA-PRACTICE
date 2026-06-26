#include<iostream>
#include<vector>
using namespace std;
void combi(vector<int> & arr, int ind, int target, vector<int> & ds, vector<vector<int>> & ans){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[ind]<=target){
    //pick the elemnet
    ds.push_back(arr[ind]);
    combi(arr,ind,target-arr[ind],ds,ans);
    ds.pop_back();
    }
    //not pick the element
    combi(arr,ind+1,target,ds,ans);

}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int target;
    cout<<"Enter target";
    cin>>target;
    vector<int>ds;
    vector<vector<int>> ans;
    combi(arr,0,target,ds,ans);
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}