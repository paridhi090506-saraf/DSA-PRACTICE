//OPTIMAL FOR UNEQUAL NUMBER OF POSITIVES AND NEGATIVES
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
    if(arr[i]<0)
    neg.push_back(arr[i]);
    else
    pos.push_back(arr[i]);
    }
    if(pos.size()==neg.size()){
        for(int i=0;i<n/2;i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
    }
    else if(pos.size()<neg.size()){
        for(int i=0;i<pos.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++)
        {
            arr[index]=neg[i];
            index++;
        }
    }
    else{
        for(int i=0;i<neg.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++)
        {
            arr[index]=pos[i];
            index++;
        }
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
//TC-O(2N)
//SC-O(N) 



//OPTIMAL FOR EQUAL NUMBER OF NEGATIVES AND POSITIVES
/*#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int pos=0,neg=1;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[neg]=arr[i];
            neg+=2;
        }
        else{
            ans[pos]=arr[i];
            pos+=2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
//tc-O(N)
//SC-O(N)
*/
//BRUTE
/*
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i]; 
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
    if(arr[i]<0)
    neg.push_back(arr[i]);
    else
    pos.push_back(arr[i]);
    }
    for(int i=0;i<n/2;i++){
    arr[2*i]=pos[i];
    arr[2*i+1]=neg[i];
    }
    for(int i=0;i<n;i++)
    cout<<arr[i];
}
//TC-O(N+N/2)
//SC-O(N/2+N/2)*/