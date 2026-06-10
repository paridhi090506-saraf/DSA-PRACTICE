#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool bouquet(vector<int> & arr, int days,int m,int k){
    int count=0,noB=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=days){
            count++;
        }
        else{
            noB+=(count/k);
            count=0;
        }
    }
    noB+=(count/k);
    if(noB>=m)
    return true;
    else
    return false;
}
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m,k;
    cout<<"Enter the number of bouquets"<<endl;
    cin>>m;
    cout<<"Enter the number of adjacent flowers required"<<endl;
    cin>>k;
    if(n < m * k){
    cout << -1 << endl;
    return 0;
}
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    for(int i=mini;i<=maxi;i++){
        if(bouquet(arr,i,m,k)==true){
            cout<<"Minimum days="<<i<<endl;
            return 0;
        }
    }
    return -1;

}