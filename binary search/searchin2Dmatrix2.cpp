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
    int row=0,col=m-1;
    while(row<n && col>=0){
        if(arr[row][col]==target){
            cout<<"Found at row "<<row<<" and column "<<col<<endl;
            return 0;
        }
        else if(arr[row][col]>target){
            col--;
        }
        else
        row++;
    }
    cout<<"Not found"<<endl;
}

//for brute force run two loops i and j and check
//for better run 1 loop for i and for each i apply binary search 