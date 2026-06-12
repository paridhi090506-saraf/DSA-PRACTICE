#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
bool canWePlace(vector<int> & arr,int dist, int k){
    int cntCows=1;
    int last=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=dist){
            cntCows++;
            last=arr[i];
        }
        if(cntCows==k)
        return true;
    }
    return false;
}
int main(){
    int k,n;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<"Enter the number of cows";
    cin>>k;
    int ans=INT_MIN;
    for(int i=1;i<=(arr[n-1]-arr[0]);i++)
    {
        if(canWePlace(arr,i,k)==true){
            continue;
        }
        else{
        ans=i-1;
        break;
        }
    }
    cout<<"Minimum distance between cows which is maximum="<<ans<<endl;
}