//smallest index such that arr[index]>x
#include<iostream>
#include<vector>
using namespace std;
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
    cout<<"Enter upper bound value";
    cin>>x;
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>x){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout<<"Index is "<<ans<<endl;
}

