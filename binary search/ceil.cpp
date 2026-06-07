//exactly same as lower bound.. 
//smallest NUMBER such that it is >=x
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
    cout<<"Enter value for which we want ceil value";
    cin>>x;
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            high=mid-1;
            ans=arr[mid];
        }
        else{
            low=mid+1;
        }
    }
    if(ans==-1)
    cout<<"No ceil value exists";
    else
    cout<<"Value "<<x<<" has ceil value of "<<ans<<endl;

}