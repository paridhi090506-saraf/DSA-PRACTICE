//THIS IS DUPLICATE ELEMENTS
//CRUCIAL PART IS TO CHECK WHICH PART OF THE ARRAY IS SORTED
// and if low,mid and high have same element then low++;high--;continue;
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
            cout<<"Present"<<endl;
            return 0;
        }
        if(arr[mid]==arr[low] && arr[mid]==arr[high])
        {
            low++;
            high--;
            continue;
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
        