#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        bool swap=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=true;
            }
        }
        if(!swap)
        break;
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

//push the max to the last by ADJACENT swapping
//TC-O(N^2)-worst and average
//tc-O(N)-best because of swap variable which we are using