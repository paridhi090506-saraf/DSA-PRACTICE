#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums){
    stack<int> st;
    vector<int> v(nums.size());
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i])
        st.pop();
        if(st.empty())
        v[i]=-1;
        else
        v[i]=st.top();
        st.push(nums[i]);
    }
    return v;
}
int main(){
    vector<int> num={6,1,8,0,3};
    vector<int> n=nextGreaterElement(num);
    for(int i=0;i<n.size();i++)
    cout<<n[i]<<" ";
    return 0;
}

//TC- O(2N)
//SC-O(2N)

//monostack used