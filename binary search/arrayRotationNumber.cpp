//Number of rotations = Index of the minimum element.
//FOR UNIQUE ELEMENTS
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
    int index=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(arr[mid]<mini){
                mini=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
        cout<<"Number of times the array is rotated is "<<index<<endl;
}*/

//FOR DUPLICATE ELEMENTS
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
    int index=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            if(arr[low] < mini){
                mini = arr[low];
                index = low;
            }
            low++;
            high--;
            continue;
        }
        if(arr[low]<arr[high]){
            if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(arr[mid]<mini){
                mini=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
        cout<<"Number of times the array is rotated is "<<index<<endl;
}
