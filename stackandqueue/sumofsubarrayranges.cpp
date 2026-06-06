#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> findnse(vector<int> & arr){
    stack<int> st;
    vector<int> nse(arr.size());
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i])
        st.pop();
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findnge(vector<int> & arr){
    stack<int> st;
    vector<int> nge(arr.size());
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i])
        st.pop();
        nge[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nge;
}
vector<int> findpgee(vector<int> & arr){
    stack<int> st;
    vector<int> pgee(arr.size());
    int n=arr.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i])
        st.pop();
        pgee[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pgee;
}
vector<int> findpsee(vector<int> & arr){
    stack<int> st;
    vector<int> psee(arr.size());
    int n=arr.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i])
        st.pop();
        psee[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return psee;
}
int sumMin(vector<int> & arr){
    int mod=1e9+7;
    vector<int> nse=findnse(arr);
    vector<int> psee= findpsee(arr);
    long long minsum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        long long left=i-psee[i];
        long long right=nse[i]-i;
        minsum=(minsum+(left*right*arr[i]*1LL)%mod)%mod;
    }
    return minsum;
}
int sumMax(vector<int> & arr){
    int mod=1e9+7;
    vector<int> nge=findnge(arr);
    vector<int> pgee= findpgee(arr);
    long long maxsum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        long long left=i-pgee[i];
        long long right=nge[i]-i;
        maxsum=(maxsum+(left*right*arr[i]*1LL)%mod)%mod;
    }
    return maxsum;
}
int main(){
    vector<int> arr={3,1,2,4};
    int mini=sumMin(arr);
    int maxi=sumMax(arr);
    int sum=maxi-mini;
    cout<<sum;
    return 0;
}

//TC-O(10N)
//SC-O(10N)