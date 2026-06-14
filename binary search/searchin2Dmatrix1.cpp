#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    int low=0,high=n*m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=mid/m;
        int col=mid%m;
        if(arr[row][col]==target){
            cout<<"found"<<endl;
            return 0;
        }
        else if(arr[row][col]<target){
            low=mid+1;
        }
        else
        high=mid-1;
    }
    cout<<"not found"<<endl;
}