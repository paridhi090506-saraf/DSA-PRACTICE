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
    int element;
    cout<<"Enter the element to be searched"<<endl;
    cin>>element;
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            index=i;
            break;
        }
    }
    cout<<"Element is found at index "<<index<<endl;
}