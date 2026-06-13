//Minimize the maximum pages that can be allocated to a student
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int studentsNum(vector<int> & arr,int pages){
    int stu=1,pagesStu=0;
    for(int i=0;i<arr.size();i++){
        if(pagesStu+arr[i]<=pages){
            pagesStu+=arr[i];
        }
        else{
            stu++;
            pagesStu=arr[i];
        }
    }
    return stu;
}
int main(){
    int n,students;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array (number of pages)";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of students";
    cin>>students;
    int low=*max_element(arr.begin(), arr.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int high=sum;
    if(arr.size()<students){
        cout<<"Not possible"<<endl;
        return 0;
    }
    while (low<=high){
        int mid=low+(high-low)/2;
        if(studentsNum(arr,mid)<=students){
            //ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    cout<<"Minimum of the maximum pages that can be allocated to a student="<<low<<endl;
}
    
/*int main(){
    int n,students;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array (number of pages)";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of students";
    cin>>students;
    int low=*max_element(arr.begin(), arr.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int high=sum;
    for(int i=low;i<=high;i++){
        if(studentsNum(arr,i)==students){
            cout<<"Minimum of the maximum pages that can be allocated to a student="<<i<<endl;
            break;
        }
    }
}*/
