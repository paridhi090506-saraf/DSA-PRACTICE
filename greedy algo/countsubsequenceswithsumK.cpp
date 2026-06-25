#include<iostream>
#include<vector>
using namespace std;
int printf(int arr[],int sum,int s,int n,int ind){
    if(s>sum)return 0;
    if(ind == n){
        if(s==sum){
            return 1;
        }
        return 0;
    }
    s+=arr[ind];
    int l=printf(arr,sum,s,n,ind+1);
    s-=arr[ind];
    int r=printf(arr,sum,s,n,ind+1);
    return l+r;
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int sum;
    cout<<"Enter sum";
    cin>>sum;
    cout<<printf(arr,sum,0,n,0);
    return 0;
}