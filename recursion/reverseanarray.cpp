#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void reversearr(int i,vector<int> & arr){
    if(i>=(arr.size()/2))
    return;
    swap(arr[i],arr[arr.size()-i-1]);
    reversearr(i+1,arr);
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    reversearr(0,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}

//we can also have l and r as parameters and have base case as if(l>=r) return; swap(arr[l],arr[r]);  f(l+1,r-1,arr);
//and in main f(0,n-1,arr)