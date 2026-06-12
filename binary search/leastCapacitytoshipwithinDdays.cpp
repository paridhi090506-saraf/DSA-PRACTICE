//The word is least/minimum so we have to do binary search on answers
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int reqDays(vector<int> & arr, int capacity){
    int days=1,load=0;
    for(int i=0;i<arr.size();i++){
        if(load+arr[i]>capacity){
            load=arr[i];
            days+=1;
        }
        else
        load+=arr[i];
    }
    return days;
}
int main(){
    int days,n;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter days";
    cin>>days;
    int maxi=*max_element(arr.begin(),arr.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int low=maxi;
    int high=sum;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(reqDays(arr,mid)<=days){
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    cout<<"Capacity of ship="<<ans<<endl;//ans will be equal to low so we can return low directly instead of answers... 
    //low starts on not possible end and high is on possible values end so low ends up on minimum possible value and high on maximum not possible value
    return 0;
}
//BRUTE
/*int main(){
    int days,n;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter days";
    cin>>days;
    int maxi=*max_element(arr.begin(),arr.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    for(int i=maxi;i<=sum;i++){
        if(reqDays(arr,i)<=days)
        return i;
    }
}
*/