//optimal
//MOORE'S VOTING ALGORITHM
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
    int count=0,element=-1;
    for(int i=0;i<n;i++){
        if(count==0){
            element=arr[i];
            count++;
        }
        else if(arr[i]==element){
            count++;
        }
        else
        count--;
    }
    int count1=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        count1++;
    }
    if(count1>n/2)
    cout<<element<<endl;
    else
    cout<<"No majority element"<<endl;
}

//TC-O(2N)
//SC-O(1)

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
    count=0;
    for(int j=0;j<n;j++){
    if(arr[i]==arr[j])
    count++;
    }
    if(count>n/2)
    break;
    }
    cout<<arr[i];
}

tc-o(n^2)
*/

//better
/*#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    map<int,int> mpp;
    for(int i=0;i<n;i++){
    mpp[arr[i]]++;}
    for(auto it:mpp){
    if(it.second>n/2){
    cout<<it.first;
    break;}
    }
}
    //tc-O(NlogN)+O(N)
    //sc-O(n) it will be so if array has all uniques numbers.. to optimize space complexity we have optimal solution
    */