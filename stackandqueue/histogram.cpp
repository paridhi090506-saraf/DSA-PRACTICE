#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int maxArea(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    int area=0;
    int nse=0,pse=0;
    int element;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            element=st.top();
            st.pop();
            pse=(st.empty())?-1:st.top();
            nse=i;
            area=max(area,(arr[element]*(nse-pse-1)));
        }
        st.push(i);
    }
    while(!st.empty()){
        nse=n;
        element=st.top();
        st.pop();
        pse=(st.empty())?-1:st.top();
        area=max(area,(arr[element]*(nse-pse-1)));
    }
    return area;
}
int main(){
    vector<int> arr={3,2,10,11,5,10,6,3};
    cout<<maxArea(arr);
    return 0;
}

//monostack increasing