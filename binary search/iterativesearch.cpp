#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements";
    cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter the elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element to be searched";
    cin>>target;
    int low=0;
    int high=n-1;
    bool flag=false;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)
        {
            flag=true;
            break;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(flag==false){
        cout<<"Not found";

    }
    else
    cout<<"Found";

}