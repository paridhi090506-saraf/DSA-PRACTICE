#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes";
    cin>>n;
    int arr[n];
    cout<<"Enter the burst time of each process";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int t=0, wt=0;
    for(int i=0;i<n;i++)
    {
        wt+=t;
        t+=arr[i];
    }
    cout<<"Average waiting time="<<(wt/n);
    return 0;
}

//time complexity- O(nlogn+n)
//space complexity- O(1)