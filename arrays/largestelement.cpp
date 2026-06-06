#include<iostream>
using namespace std;
int main(){
    int arr[]={2,1,5,3,7,7,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(largest<arr[i])
        largest=arr[i];
    }
    cout<<"Largest element="<<largest<<endl;
    return 0;
}

//TC-O(N)
//BRUTE FORCE IS SORTING THE ARRAY AND PRINTING arr[n-1]   TC-O(NlogN)