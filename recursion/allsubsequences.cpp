#include<iostream>
#include<vector>
using namespace std;
void subs(vector<int> & ds,int arr[],int n, int ind){
    if(ind==n){
        for(auto it:ds)
        cout<<it<<" ";
        if(ds.size()==0)
        cout<<"{}";
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    subs(ds,arr,n,ind+1);
    ds.pop_back();
    subs(ds,arr,n,ind+1);
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> ds;
    subs(ds,arr,n,0);
    return 0;
}