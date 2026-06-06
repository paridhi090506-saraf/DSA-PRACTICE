//OPTIMAL
#include<iostream>
using namespace std;
void reverse(int start,int end,int arr[]){
while(start<=end){
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++;
    end--;
}
}
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int d;
    cout<<"Enter the number of digits "<<endl;
    cin>>d;
    d=d%n;
    reverse(0,d-1,arr); //for left rotation
    //For right rotation reverse(0,n-d-1,arr), reverse(n-d,n-1,arr), reverse(0,n-1,arr)
    reverse(d,n-1,arr);
    reverse(0,n-1,arr);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
//we can directly reverse by using include<algorithm> and doing reverse(arr,arr+d) and all other reverses without having to write reverse function



/*BRUTE
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
    int d;
    cout<<"Enter the number of digits "<<endl;
    cin>>d;
    d=d%n;
    int temp[d];
    for(int i=0;i<d;i++)
    temp[i]=arr[i];
    for(int i=d;i<n;i++)
    arr[i-d]=arr[i];
    for(int i=n-d;i<n;i++)
    arr[i]=temp[i-n+d];
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}

//tc- O(N+D)
//SC- O(D)
*/