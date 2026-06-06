/*
#include<iostream>
#include<vector>
using namespace std;
int sumsubarrayMin(vector<int> &arr){
int sum=0;
int mod=(int)(1e9+7);
int n=arr.size();
for(int i=0;i<n;i++){
int mini=arr[i];
for(int j=i;j<n;j++){
mini=min(mini,arr[j]);
sum=(sum+mini)%mod;
}
}
return sum;
}
int main(){
vector<int> arr={3,1,2,4};
cout<<sumsubarrayMin(arr);
return 0;
}

TC-O(N^2)
SC-O(1)*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> findnse(vector<int> &arr){
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
vector<int> findpsee(vector<int> &arr){
    stack<int> st;
    vector<int> psee(arr.size());
    int n=arr.size();
    for(int i=0;i<=n-1;i++){
        while(!st.empty() && arr[st.top()]>arr[i])
        st.pop();
        psee[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return psee;
}
int sum(vector<int> &arr){
    int mod = 1e9 + 7;

    vector<int> nse = findnse(arr);
    vector<int> psee = findpsee(arr);
    long long sum = 0;
    for(int i = 0; i < arr.size(); i++){
        long long left = i - psee[i];
        long long right = nse[i] - i;
        sum = (sum + (left * right * arr[i] * 1LL) % mod) % mod;
    }
    return sum;
}
int main(){
    vector<int> arr={1,4,6,7,3,7,8,1};
    cout<<sum(arr);
    return 0;
}

//TC-O(5N)
//SC-O(5N)