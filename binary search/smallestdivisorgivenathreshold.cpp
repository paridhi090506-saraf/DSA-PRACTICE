#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int divisor(vector<int> & arr,int div){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=((arr[i]+div-1)/div);
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter the number of elements in an array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter threshold value";
    cin>>x;
    int ans=0;
    int low=1;
    int high=*max_element(arr.begin(),arr.end());
    while(low<=high){
        int mid=low+(high-low)/2;
        if(divisor(arr,mid)<=x){
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    cout<<ans<<endl;
}