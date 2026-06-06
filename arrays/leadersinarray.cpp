//OPTIMAL
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int maxi=INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi)
        ans.push_back(arr[i]);
        maxi=max(maxi,arr[i]);
    }
    for(auto it:ans)
    cout<<it<<" ";
}




//BRUTE
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j])
            {
                leader=false;
                break;
            }
        }
        if(leader==true)
        ans.push_back(arr[i]);
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}*/
//TC-O(N^2)
//SC-O(N)