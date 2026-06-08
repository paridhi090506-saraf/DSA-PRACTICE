//FOR UNIQUE ELEMENTS
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in an array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low]<=arr[high]){
            mini=min(mini,arr[low]);
            break;
        }
        if(arr[low]<=arr[mid])
        {
            mini=min(mini,arr[low]);
            low=mid+1;
        }
        else{
            mini=min(mini,arr[mid]);
            high=mid-1;
        }
    }
    cout<<"Minimum element is "<<mini<<endl;
}


//FOR DUPLICATE ELEMENTS
/*#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in an array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            mini = min(mini, arr[low]);
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[high]){
            mini=min(mini,arr[low]);
            break;
        }
        if(arr[low]<=arr[mid])
        {
            mini=min(mini,arr[low]);
            low=mid+1;
        }
        else{
            mini=min(mini,arr[mid]);
            high=mid-1;
        }
    }
    cout<<"Minimum element is "<<mini<<endl;
}*/