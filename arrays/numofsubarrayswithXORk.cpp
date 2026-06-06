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
    map<int,int> mpp;
    int prefixXor=0;
    int count=0;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        prefixXor=prefixXor^arr[i];
        int x=prefixXor^k;;
        count+=mpp[x];
        mpp[prefixXor]++;
    }
    cout<<"Total count="<<count<<endl;
}


/*#include<iostream>
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
    int count=0;
    for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
    int xor=0;
    for(int t=i;t<=j;t++){
    xor=xor^arr[t];
    }
    if(xor==k)
    count++;
    }
    }
    cout<<count<<endl;
}*/


/*#include<iostream>
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
    int count=0;
    for(int i=0;i<n;i++){
    int xor=0;
    for(int j=i;j<n;j++){
    xor=xor^arr[j];
    if(xor==k)
    count++;
    }
    }
    cout<<count<<endl;
}*/