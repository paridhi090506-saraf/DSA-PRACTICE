//works for 1 peak as well as more than one peak
//for multiple peaks it can return any peak.
// peak element: arr[i-1]<arr[i]>arr[i+1]
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
    if(n==1)
    {
        cout<<"Peak element "<<arr[0]<<" is found at index 0"<<endl;
        return 0;
    }
    if(arr[0]>arr[1]){
        cout<<"Peak element "<<arr[0]<<" is found at index 0"<<endl;
        return 0;
    }
    if(arr[n-1]>arr[n-2]){
        cout<<"Peak element "<<arr[n-1]<<" is found at index "<<(n-1)<<endl;
        return 0;
    }
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[mid+1] && arr[mid-1]<arr[mid]){
            cout<<"Peak element "<<arr[mid]<<" is present at index "<<mid<<endl;
            return 0;
        }
        else if(arr[mid-1]<arr[mid]){
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return -1;
}


/*while(low < high){
    int mid = low + (high-low)/2;

    if(nums[mid] < nums[mid+1])
        low = mid + 1;
    else
        high = mid;
}
return low;*/

//Brute
/*int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    for(int i = 1; i <= n-2; i++) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            return i;
        }
    }
    return -1;
}*/