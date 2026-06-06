//optimal-gap method(shell sort)
/*#include<iostream>
using namespace std;
void swapGreater(int arr1[],int arr2[],int n1,int n2)
{
    if(arr1[n1]>arr2[n2])
    swap(arr1[n1],arr2[n2]);
}
int main(){
    int n1,n2;
    cout<<"Enter the number of elements in array1"<<endl;
    cin>>n1;
    cout<<"Enter the number of elements in array2"<<endl;
    cin>>n2;
    int arr1[n1],arr2[n2];
    cout<<"Enter the elements of array 1"<<endl;
    for(int i=0;i<n1;i++)
    cin>>arr1[i];
    cout<<"Enter the elements of array 2"<<endl;
    for(int i=0;i<n2;i++)
    cin>>arr2[i];
    int len=n1+n2;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
        //arr1 and arr2
        if(left<n1 && right>=n1){
            swapGreater(arr1,arr2,left,right-n1);
        }
        //arr2 and arr2
        else if(left>=n1){
            swapGreater(arr2,arr2,left-n1,right-n1);
        }
        //arr1 and arr1
        else{
            swapGreater(arr1,arr1,left,right);
        }
        left++;
        right++;
    }
    if(gap==1)
    break;
    gap=(gap/2)+(gap%2);
    }
    cout<<"After merging"<<endl;
    for(int i=0;i<n1;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<n2;i++){
        cout<<arr2[i]<<" ";
    }
}*/



/*#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n1,n2;
    cout<<"Enter the number of elements in array1"<<endl;
    cin>>n1;
    cout<<"Enter the number of elements in array2"<<endl;
    cin>>n2;
    int arr1[n1],arr2[n2];
    cout<<"Enter the elements of array 1"<<endl;
    for(int i=0;i<n1;i++)
    cin>>arr1[i];
    cout<<"Enter the elements of array 2"<<endl;
    for(int i=0;i<n2;i++)
    cin>>arr2[i];
    int left=n1-1;
    int right=0;
    while(left>=0 && right<n2){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else
        break;
    }
    sort(arr1,arr1+n1);
    sort(arr2,arr2+n2);
    for(int i=0;i<n1;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<n2;i++){
        cout<<arr2[i]<<" ";
    }
}
*/

//BRUTE
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n1,n2;
    cout<<"Enter the number of elements in array1"<<endl;
    cin>>n1;
    cout<<"Enter the number of elements in array2"<<endl;
    cin>>n2;
    int arr1[n1],arr2[n2];
    cout<<"Enter the elements of array 1"<<endl;
    for(int i=0;i<n1;i++)
    cin>>arr1[i];
    cout<<"Enter the elements of array 2"<<endl;
    for(int i=0;i<n2;i++)
    cin>>arr2[i];
    int arr3[n1+n2];
    int left=0,right=0;
    int index=0;
    while(left<n1 && right<n2){
        if(arr1[left]<=arr2[right]){
            arr3[index]=arr1[left];
            index++;
            left++;
        }
        else{
            arr3[index]=arr2[right];
            index++;
            right++;
        }
    }
    while(left<n1){
        arr3[index++]=arr1[left++];
    }
    while(right<n2){
        arr3[index++]=arr2[right++];
    }
    for(int i=0;i<n1+n2;i++){
        cout<<arr3[i]<<" ";
    }
}
//but it is using xtra space which we don't have to use
