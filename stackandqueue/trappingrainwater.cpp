/*two pointer approach*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int water(vector<int> &arr){
    int n=arr.size();
    int l=0,r=n-1;
    int leftMax=0,rightMax=0,total=0;
    while(l<r){
        if(arr[l]<=arr[r]){
            if(leftMax>arr[l])
            total+=leftMax-arr[l];
            else
            leftMax=arr[l];
            l=l+1;
        }
        else{
             if(rightMax>arr[r])
            total+=rightMax-arr[r];
            else
            rightMax=arr[r];
            r=r-1;
        }
    }
    return total;
}
int main(){
    vector<int> arr= {4,2,0,3,2,5};
    cout<<water(arr);
    return 0;
}
//TC-O(N)
//SC-O(1)


/*
prefix suffix approach

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int water(vector<int> &arr){
    int n=arr.size();
    int prefixMax[n];
    int suffixMax[n];
    prefixMax[0]=arr[0];
    suffixMax[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        prefixMax[i]=max(prefixMax[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i+1],arr[i]);
    }
    int total=0;
    for(int i=0;i<=n-1;i++){
        int leftMax=prefixMax[i];
        int rightMax=suffixMax[i];
        total+=min(leftMax,rightMax)-arr[i];
    }
    return total;
}
int main(){
    vector<int> arr= {4,2,0,3,2,5};
    cout<<water(arr);
    return 0;
}
    
tc-O(3N)
SC-O(2N)


suffix approach

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int water(vector<int> &arr){
    int n=arr.size();
    int suffixMax[n];
    int prefixMax=arr[0];
    suffixMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i+1],arr[i]);
    }
    int total=0;
    for(int i=0;i<=n-1;i++){
        prefixMax=max(prefixMax,arr[i]);
        int leftMax=prefixMax;
        int rightMax=suffixMax[i];
        total+=min(leftMax,rightMax)-arr[i];
    }
    return total;
}
int main(){
    vector<int> arr= {4,2,0,3,2,5};
    cout<<water(arr);
    return 0;
}

TC-O(2N)
SC-O(N)*/