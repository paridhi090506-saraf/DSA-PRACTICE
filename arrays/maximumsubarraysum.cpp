//OPTIMAL
//KADANE'S ALGO
#include<iostream>
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
    int maxi=INT_MIN;int sum=0;
    int start=0,ansStart=-1,ansEnd=-1;
    for(int i=0;i<n;i++){
        if(sum==0)
        start=i;
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }
        if(sum<0)
        sum=0;
    }
    cout<<"Maximum subarray sum="<<maxi<<endl;
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
}







/*#include<iostream>
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
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
                sum+=arr[j];
                maxi=max(maxi,sum);
        }
    }
    cout<<"Maximum subarray sum="<<maxi<<endl;
}
//TC-O(N^2)
//SC-O(1)
*/


//BRUTE
/*#include<iostream>
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
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            maxi=max(maxi,sum);
        }
    }
    cout<<"Maximum subarray sum="<<maxi<<endl;
}

//TC-O(N^3)
//SC-O(1)*/