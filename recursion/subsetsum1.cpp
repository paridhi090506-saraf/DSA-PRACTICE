#include<iostream>
#include<vector>
using namespace std;
void subsetsum(vector<int> & arr, int ind, int sum, int n, vector<int> & subsetSum){
    if(ind==n){
        subsetSum.push_back(sum);
        return;
    }
    subsetsum(arr,ind+1,sum+arr[ind],n,subsetSum);
    subsetsum(arr,ind+1,sum,n,subsetSum);
}
int main(){
    int n;
    cout<<"Enter the number of elements of an array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of an array";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> subsetSum;
    subsetsum(arr,0,0,n,subsetSum);
    for(auto it: subsetSum){
        cout<<it<<" ";
    }
    return 0;
}