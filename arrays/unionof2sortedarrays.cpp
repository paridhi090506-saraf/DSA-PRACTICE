#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n1,n2;
    cout<<"Enter the number of elements in array1"<<endl;
    cin>>n1;
    cout<<"Enter the number of elements in array2"<<endl;
    cin>>n2;
    int arr1[n1],arr2[n2];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n1;i++)
    cin>>arr1[i];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n2;i++)
    cin>>arr2[i];
    int i=0,j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
    while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    for(int i=0;i<unionArr.size();i++)
    cout<<unionArr[i]<<" ";
}

//TC-O(N1+N2)
//SC-O(N1+N2)

//FOR BRUTE FORCE SINCE UNION HAS UNIQUE SORTED VALUES WE WILL USE SET AND TC WILL BE O(N1LOGN1+N2LOGN2+N1+N2)