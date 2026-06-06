//optimal
//dutch national flag algo
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" "; 
}

//TC-O(N)
//SC-O(1)
//For brute force method, it is that we perform merge sort tc-O(NlogN)

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
    int zero=0,ones=0,twos=0;
    for(int i=0;i<n;i++)
    {
    if(arr[i]==0)
    zero++;
    else if(arr[i]==1)
    ones++;
    else
    twos++;
    }
    int i=0;
    while(zeros>0){
    arr[i++]=0;
    zeros--;
    }
    while(ones>0){
    arr[i++]=1;
    ones--;

    }
    while(twos>0){
    arr[i++]=2;
    twos--;
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl
}
    //TC-O(2N)
*/