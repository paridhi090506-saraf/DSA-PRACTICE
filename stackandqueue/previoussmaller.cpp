#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> smallerEl(vector<int>& nums){
    vector<int> ans(nums.size());
    stack<int> st;
    for(int i=0;i<nums.size();i++){
    while(!st.empty() && st.top()>=nums[i]){
        st.pop();
    }
    if(st.empty())
    ans[i]=-1;
    else
    ans[i]=st.top();
    st.push(nums[i]);
    }
    return ans;
}
int main(){
    vector<int> v={5,7,9,6,7,4,5,1,3,7};
    vector<int> res=smallerEl(v);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    return 0;
}
//TC-O(2N)
//SC-O(2N)
//monostack used(increasing order)