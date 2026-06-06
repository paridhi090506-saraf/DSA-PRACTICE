#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int profit=0,mini=arr[0];
    for(int i=1;i<n;i++){
        int cost=arr[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,arr[i]);
    }
    cout<<"Maximum profit="<<profit;
}
//TC-O(N)
//SC-O(1)