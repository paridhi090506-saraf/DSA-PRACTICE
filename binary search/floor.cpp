//exactly same as lower bound.. 
//largest NUMBER such that it is <=x
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
    cout<<"Enter value for which we want floor value";
    cin>>x;
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<=x){
            ans=arr[mid];
            low=mid+1;
        }
        else
        high=mid-1;
    }
    if(ans==-1)
    cout<<"No floor value exists";
    else
    cout<<"Value "<<x<<" has floor value "<<ans<<endl;
}