#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int k;
    cout<<"Enter k";
    cin>>k;
    int prefixSum=0;
    int count=0;
    map<int,int> mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        prefixSum+=arr[i];
        int remove=prefixSum-k;
        count+=mpp[remove];
        mpp[prefixSum]++;
    }
    cout<<"Number of subarrays with sum k="<<count<<endl;
}
//TC-O(N)

/*BRUTE
#include<iostream>
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
    int t;
    cout<<"Enter k";
    cin>>t;
    int count=0;
    for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
    int sum=0;
    for(int k=i;k<=j;k++){
    sum+=arr[k];
    }
    if(sum==t)
    count++;
    }
    }
    cout<<count<<endl;
}


BETTER
#include<iostream>
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
    int t;
    cout<<"Enter k";
    cin>>t;
    int count=0;
    for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
    sum+=arr[j];
    if(sum==t)
    count++;
    }
    }
    cout<<count<<endl;
}*/