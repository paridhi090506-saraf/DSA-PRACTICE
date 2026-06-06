#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,1,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool flag=true;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            flag=false;
            break;
        }
    }
    if(flag==true)
    cout<<"Yes the array is sorted"<<endl;
    else
    cout<<"No the array is not sorted"<<endl;
    return 0;
}