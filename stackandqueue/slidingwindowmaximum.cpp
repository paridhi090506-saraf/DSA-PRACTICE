/*BRUTE FORCE 
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector <int> window(vector<int> & arr,int k){
    int n=arr.size();
    vector<int> v(n-k+1);
    for(int i=0;i<=n-k;i++){
        int maxi=arr[i];
        for(int j=i;j<i+k;j++){
            maxi=max(maxi,arr[j]);
        }
        v[i]=maxi;
    }
    return v;
}
int main(){
    vector<int> arr={1,3,-1,-3,5,3,2,1,6};
    int k=3;
    vector<int> ans=window(arr,k);
    for(int x:ans)
    cout<<x<<" ";
    return 0;
}

//TC-O(N-K)*O(K)
//SC-O(N-K)
*/

#include<iostream>
#include<deque>
#include<vector>
using namespace std;
vector<int> window(vector<int> &arr,int k){
    int n=arr.size();
    deque<int> dq;
    vector<int> v;
    for(int i=0;i<=n-1;i++){
        //to maintin the window
        while(!dq.empty() && dq.front()<=i-k)
        dq.pop_front();
        //to contain index in decreasing order of values in monostack
        while(!dq.empty() && arr[dq.back()]<=arr[i])
        dq.pop_back();
        dq.push_back(i);
        if(i>=k-1){
            v.push_back(arr[dq.front()]);
        }
    }
    return v;
}
int main(){
    vector<int> arr={1,3,-1,-3,5,3,2,1,6};
    int k=3;
    vector<int> ans=window(arr,k);
    for(int x:ans)
    cout<<x<<" ";
    return 0;
}

//tc-O(2N)
//SC-O(K)+O(N-K)