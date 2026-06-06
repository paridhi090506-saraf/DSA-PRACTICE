#include<iostream>
#include<vector>
using namespace std;
long long merge(int arr[],int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    long long count=0;
    while(left<=mid && right<=high){
    if(arr[left]<=arr[right]){
    temp.push_back(arr[left]);
    left++;
    }
    else{
        count+=(mid-left+1);
    temp.push_back(arr[right]);
    right++;
    }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return count;
}
long long mergeSort(int arr[],int low,int high){
    long long count=0;
    if(low>=high)
    return count;
    int mid=(low+high)/2;
    count+=mergeSort(arr,low,mid);
    count+=mergeSort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);
    return count;
}
long long inversions(int arr[],int n){
    return mergeSort(arr,0,n-1);
}


int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    long long count=inversions(arr,n);
    cout<<count<<endl;
}



//BRUTE
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
            count++;
        }
    }
    cout<<count<<endl;
}*/



