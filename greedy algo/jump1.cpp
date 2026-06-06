#include<iostream>
#include<algorithm>
using namespace std;
bool jump(int arr[], int n){
    int maxInd=0;
    for(int i=0;i<n;i++){
    if(i>maxInd)
    return false;
    maxInd=max(maxInd, i+arr[i]);
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter thr value of n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array values";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    if(jump(arr,n)){
        cout<<"Yes reached the end";
    }
    else
    cout<<"Cannot reach the end";
    return 0;
}

//time complexity- O(n)
//space complexity- O(1)
// if able to cross the zeroes then you will reach the end
//if no zeroes then you will definitely reach the end
//the catch in this problem is zero, nothing else