#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
    reverse(arr,arr+n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
        return 0;
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr+index+1,arr+n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}
//what we are doing is we get the longest prefix... the index decididing part
//then we swap it with the one which is greater than the arr[index] but it should be the smallest among all other greater than arr[index] elements
//and then reverse the remaining ones.. do a dry run and you'll understand
//TC-O(3N)
//SC-O(1)

//FOR BETTER WE CAN DIRECTLY USE STL FUNCTION WHICH IS next_permutation
//For brute we can generate all parenthesis(recursion lecture 12 and 13) the by linear search locate the given array then print the next one.. if it is the last then print the first one
//tc-O(N!*N) which is bohot zyadaaaa