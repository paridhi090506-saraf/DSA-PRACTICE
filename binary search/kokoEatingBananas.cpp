#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int hours(vector<int> & arr, int hourly){
    int totalHrs=0;
    for(int i=0;i<arr.size();i++){
        totalHrs+=((arr[i]+hourly-1)/hourly);
    }
    return totalHrs;
}
int main(){
    int h,n;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter hours";
    cin>>h;
    int maxi=*max_element(arr.begin(),arr.end());
    int low=1;
    int high=maxi;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(hours(arr,mid)<=h){
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}


/*int main(){
    int h,n;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter hours";
    cin>>h;
    int maxi=*max_element(arr.begin(),arr.end());
    for(int i=1;i<=maxi;i++){
        if(hours(arr,i)<=h){
            cout<<i<<endl;
            break;
        }
    }
    return 0;

}*/