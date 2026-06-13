#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int numberPainters(vector<int> & arr,int boardLength){
    int painter=1;
    int boardsPainter=0;
    for(int i=0;i<arr.size();i++){
        if(boardsPainter+arr[i]<=boardLength){
            boardsPainter+=arr[i];
        }
        else{
            painter++;
            boardsPainter=arr[i];
        }
    }
    return painter;
}
int main(){
    int n,painters;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array (number of pages)";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of painters";
    cin>>painters;
    int low=*max_element(arr.begin(), arr.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int high=sum;
    if(painters>arr.size()){
        cout<<"Not possible"<<endl;
        return 0;
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(numberPainters(arr,mid)<=painters){
            //ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    cout<<"Minimum of the maximum workload shared among painters="<<low<<endl;
}
/*int main(){
    int n,painters;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array (number of pages)";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of painters";
    cin>>painters;
    int low=*max_element(arr.begin(), arr.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int high=sum;
    if(painters>arr.size()){
        cout<<"Not possible"<<endl;
        return 0;
    }
    for(int i=low;i<=high;i++){
        if(numberPainters(arr,i)==painters){
            cout<<"Minimum of the maximum workload shared among painters="<<i<<endl;
            break;
        }
    }
}*/