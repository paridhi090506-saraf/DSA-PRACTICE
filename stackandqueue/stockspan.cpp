//pge index
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> stock(vector<int> &prices){
    int n=prices.size();
    vector<int> span(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && prices[st.top()]<=prices[i])
        st.pop();
        if(st.empty())
        span[i]=i+1;
        else
        span[i]=i-st.top();
        st.push(i);
    }
    return span;

}
int main(){
    vector<int> prices={7,2,1,3,3,1,8};
    vector<int> ans=stock(prices);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}

//TC-O(2N)
//SC-O(N)