#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int prefix=1,suffix=1;
    int maxProd=INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix==0)
        prefix=1;
        if(suffix==0)
        suffix=1;
        prefix*=arr[i];
        suffix*=arr[n-i-1];
        maxProd=max(maxProd,max(prefix,suffix));
    }
    cout<<"Maximum product="<<maxProd<<endl;
}

//for brute and better it is same as max subarray sum only prod=1