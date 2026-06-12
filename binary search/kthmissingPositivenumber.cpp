#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int k,n;
    cout<<"Enter the size of array";
    cin>>n;
    cout<<"Enter the elements";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter k";
    cin>>k;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k)
        low=mid+1;
        else
        high=mid-1;
    }
    cout<< (high+k+1)<<endl;
}
//kth missing element= arr[high]+more    more=k-missing   missing=arr[high]-(high+1)
//so kth missing element =high+1+k   and high+1=low so it is low+k
//do dry run



//BRUTE
/*int main(){
    int k,n;
    cout<<"Enter the size of array";
    cin>>n;
    cout<<"Enter the elements";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter k";
    cin>>k;
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            k++;
        }
        else
        break;
    }
    cout<<"Kth missing number is "<<k<<endl;
}*/