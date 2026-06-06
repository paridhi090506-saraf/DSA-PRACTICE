#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextGE(vector<int>& nums){
    stack<int> st;
    vector<int> ans(nums.size());
    for(int i=2*nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i%nums.size()])
        st.pop();
        if(i<nums.size())
        ans[i]=(st.empty())?-1:st.top();
        st.push(nums[i%nums.size()]);
    }
    return ans;
}
int main(){
    vector<int> v={2,10,12,1,11};
    vector<int> res=nextGE(v);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    return 0;
}

//virtually double the array
//monostack used (decreasing order)