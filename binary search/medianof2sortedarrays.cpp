#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of elements in 1st array"<<endl;
    cin>>n;
    cout<<"Enter the number of elements in 2nd array"<<endl;
    cin>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    cout<<"Enter the elements of array 1"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the elements of array 2"<<endl;
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int i=0,j=0;
    int count=0;
    int ind2=(n+m)/2;
    int ind1=ind2-1;
    int el1=-1,el2=-1;
    while(i<n && j<m && count<=ind2){
        if(arr1[i]<arr2[j]){
            if(count==ind1) el1=arr1[i];
            if(count==ind2) el2=arr1[i];
            count++;
            i++;
        }
        else{
            if(count==ind1) el1=arr2[j];
            if(count==ind2) el2=arr2[j];
            count++;
            j++;
        }
    }
    while(i<n && count<=ind2){
        if(count==ind1) el1=arr1[i];
        if(count==ind2) el2=arr1[i];
        count++;
        i++;
    }
    while(j<m && count<=ind2){
        if(count==ind1) el1=arr2[j];
        if(count==ind2) el2=arr2[j];
        count++;
        j++;
    }
    if((n+m)%2==0){
        double median=(double)(el1+el2)/2.0;
        cout<<"Median of 2 sorted arrays="<<median<<endl;
        return 0;
    }
    cout<<"Median of 2 sorted arrays="<<el2<<endl;
}

/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of elements in 1st array"<<endl;
    cin>>n;
    cout<<"Enter the number of elements in 2nd array"<<endl;
    cin>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    cout<<"Enter the elements of array 1"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the elements of array 2"<<endl;
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    vector<int> arr3;
    int i=0,j=0;
    int ind2=(n+m)/2;
    int ind1=ind2-1;
    int el1=-1,el2=-1;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        arr3.push_back(arr2[j]);
        j++;
    }
    if((n+m)%2==0){
        el1=arr3[ind1];
        el2=arr3[ind2];
        double median=(double)(el1+el2)/2.0;
        cout<<"Median of 2 sorted arrays="<<median<<endl;
        return 0;
    }
    cout<<"Median of 2 sorted arrays="<<arr3[ind2]<<endl;
}*/
