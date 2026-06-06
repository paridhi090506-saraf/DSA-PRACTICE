#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={4,2,5,1,3,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int smallest=arr[0];
    int ssmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            ssmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest=arr[i];
        }
    }
    cout<<"Second smallest element="<<ssmallest<<endl;
}