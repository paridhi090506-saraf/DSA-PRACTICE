#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int numberSubarrays(vector<int> & arr,int val){
    int subarray=1;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        if(sum+arr[i]<=val){
            sum+=arr[i];
        }
        else{
            subarray++;
            sum=arr[i];
        }
    }
    return subarray;
}
int main(){
    int n,sub;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array (number of pages)";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of subarrays";
    cin>>sub;
    int low=*max_element(arr.begin(), arr.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int high=sum;
    if(sub>arr.size()){
        cout<<"Not possible"<<endl;
        return 0;
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(numberSubarrays(arr,mid)<=sub){
            //ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    cout<<"Minimum of the maximum subarray sum="<<low<<endl;
}
/*int main(){
    int n,sub;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array (number of pages)";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of subarrays";
    cin>>sub;
    int low=*max_element(arr.begin(), arr.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int high=sum;
    if(sub>arr.size()){
        cout<<"Not possible"<<endl;
        return 0;
    }
    for(int i=low;i<=high;i++){
        if(numberSubarrays(arr,i)==sub){
            cout<<"Minimum of the maximum subarray sum="<<i<<endl;
            break;
        }
    }
}*/