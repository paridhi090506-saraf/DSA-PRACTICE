#include<iostream>
#include<vector>
#include<list>
using namespace std;
list<int> collide(vector<int>& arr){
    list<int> st;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]>0)
        st.push_back(arr[i]);
        else{
            while(!st.empty() && st.back()>0 && st.back()<abs(arr[i]))
            st.pop_back();
            if(!st.empty() && st.back()==abs(arr[i]))
            st.pop_back();
            else if(st.empty() || st.back()<0)
            st.push_back(arr[i]);
        }
    }
    return st;
}
int main(){
    vector<int> arr={4,7,1,1,2,-3,-7,17,15,-16};
    list<int> ans=collide(arr);
    for(auto x: ans)
    cout<<x<<" ";
}