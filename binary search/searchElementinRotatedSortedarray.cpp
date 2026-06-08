//THIS IS ONLY FOR UNIQUE ELEMENTS
//CRUCIAL PART IS TO CHECK WHICH PART OF THE ARRAY IS SORTED
#include<iostream>
#include<vector>
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
    int x;
    cout<<"Enter the number to be searched"<<endl;
    cin>>x;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            cout<<"Present at index "<<mid<<endl;
            return 0;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=x && x<=arr[mid]){
                high=mid-1;
            }
            else
            low=mid+1;
        }
        else{
            if(arr[mid]<=x && x<=arr[high]){
                low=mid+1;
            }
            else
            high=mid-1;
        }
    }
    cout<<"Not present";
    return 0;
}
        