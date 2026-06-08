//if number is present in array then first is equal to lowerbound value and last occurence is equal to (upperbound value-1)
/*#include<iostream>
#include<vector>
using namespace std;
int lowerbound(vector<int> & arr,int n,int x){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x)
        {
            high=mid-1;
            ans=mid;
        }
        else
        low=mid+1;
    }
    return ans;
}
int upperbound(vector<int> & arr,int n,int x){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>x)
        {
            high=mid-1;
            ans=mid;
        }
        else
        low=mid+1;
    }
    return ans;
}
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
    cout<<"Enter the number whose first and last occurence is to be found"<<endl;
    cin>>x;
    int lb=lowerbound(arr,n,x);
    if(lb==n || arr[lb]!=x){
        cout<<"-1 -1"<<endl;
        return 0;
    }
    int ub=upperbound(arr,n,x);
    cout<<"First occurence="<<lb<<endl;
    cout<<"Last occurence="<<(ub-1)<<endl;
    return 0;
}
*/

//if number is present in array then first is equal to lowerbound value and last occurence is equal to (upperbound value-1)
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
    cout<<"Enter the number whose first and last occurence is to be found"<<endl;
    cin>>x;
    int low=0;
    int high=n-1;
    int first=-1,last=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]>x)
        high=mid-1;
        else{
            low=mid+1;
        }
    }
    low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<x)
        low=mid+1;
        else
        high=mid-1;
    }
    cout<<"First occurrence="<<first<<endl;
    cout<<"Last occurence="<<last<<endl;
}
//to count occurences we do last-first+1... if first=-1 then we return 0