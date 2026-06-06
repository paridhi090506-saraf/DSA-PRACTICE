#include<iostream>
using namespace std;
int main(){
    int arr[]={2,1,5,3,7,7,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int largest=arr[0];
    int slargest=-1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    cout<<"Second largest element="<<slargest<<endl;
    return 0;
}
//TC-O(N)
//Brute force.. sort the array and then run a loop from i=n-2 to 0 and within it check if largest!=arr[i], true then secondlargest=arr[i] and then break
//for this TC=O(NlogN+N)
//Better... run the loop get the largest element then take a slargest=-1 and again run a loop if(arr[i]>slargest && arr[i]!=largest) then slargest=arr[i]
//for this TC=O(N+N)=O(2N)