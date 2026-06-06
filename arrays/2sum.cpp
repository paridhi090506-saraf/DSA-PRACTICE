#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int target;
    int num1=-1,num2=-1;
    cout<<"Enter the target"<<endl;
    cin>>target;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int more=target-arr[i];
        if(mpp.find(more)!=mpp.end()){
            num1=mpp[more];
            num2=i;//it is for index for actual numbers num1=more, num2=arr[i]
            break;
        }
        mpp[arr[i]]=i;
    }
    cout<<num1<<","<<num2<<endl;
}

//TC-(O(NlogN))
//SC-O(N)
//one more way is to do it using 2 pointer approach
//in a greedy way.. first sort then take l=0,r=n-1 then if(left+right<target) left++
//else right++.. this happens while(left<right)

//or brute soln is for(i=0;i<n;i++){for(int j=i+1;j<n;j++){if(arr[i]+arr[j]==target) then arr[i] and arr[j] are the two numbers}}   tc=O(N^2)