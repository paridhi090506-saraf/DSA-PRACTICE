#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<vector<int>> prefixSum(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> prefix(n, vector<int>(m, 0));
    for(int j = 0; j < m; j++)
        prefix[0][j] = arr[0][j];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0)
                prefix[i][j] = 0;
            else
                prefix[i][j] = prefix[i-1][j] + arr[i][j];
        }
    }
    return prefix;
}
int maxArea(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    int area = 0;
    int nse, pse, element;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? -1 : st.top();
            area = max(area, arr[element] * (nse - pse - 1));
        }
        st.push(i);
    }
    while(!st.empty()){
        element = st.top();
        st.pop();
        nse = n;
        pse = st.empty() ? -1 : st.top();
        area = max(area, arr[element] * (nse - pse - 1));
    }
    return area;
}
int main(){
    vector<vector<int>> arr = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };
    vector<vector<int>> prefix = prefixSum(arr);
    int area = 0;
    for(int i = 0; i < prefix.size(); i++){
        area = max(area, maxArea(prefix[i]));
    }
    cout << area;
}

//TC=O(N*M)+O(N*2M)
//SC=O(N*M)