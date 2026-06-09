//(even,odd) then element present on right half, i.e., eliminate left half
//(odd,even) then element present on left half, i.e., eliminate right half
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
    if(arr.size()==1){
        cout<<arr[0]<<endl;
        return 0;
    }
    if(arr[0]!=arr[1]){
        cout<<arr[0]<<endl;
        return 0;
    }
    if(arr[n-1]!=arr[n-2]){
        cout<<arr[n-1]<<endl;
        return 0;
    }
    int low=1,high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            cout<<arr[mid]<<endl;
            return 0;
        }
        if(((mid%2==1) && (arr[mid]==arr[mid-1])) || ((mid%2==0) && arr[mid]==arr[mid+1])){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
    
//other methods are count approach,hashing, or xor method
//one more is
/*#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(n == 1) {
        cout << arr[0];
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if(arr[i] != arr[i + 1]) {
                cout << arr[i];
                return 0;
            }
        }
        else if(i == n - 1) {
            if(arr[i] != arr[i - 1]) {
                cout << arr[i];
                return 0;
            }
        }
        else {
            if(arr[i] != arr[i - 1] && arr[i] != arr[i + 1]) {
                cout << arr[i];
                return 0;
            }
        }
    }
    return 0;
}*/