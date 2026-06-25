#include<iostream>
#include<vector>
using namespace std;
bool printf(vector<int> & ds,int arr[],int sum,int s,int n,int ind){
    if(ind == n){
        if(s==sum){
            for(auto it:ds)
            cout<<it<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(printf(ds,arr,sum,s,n,ind+1)==true)
    return true;
    s-=arr[ind];
    ds.pop_back();
    if(printf(ds,arr,sum,s,n,ind+1)==true)
    return true;
    return false;
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> ds;
    int sum;
    cout<<"Enter sum";
    cin>>sum;
    printf(ds,arr,sum,0,n,0);
    return 0;
}