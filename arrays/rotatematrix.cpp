#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows in matrix"<<endl;
    cin>>n;
    vector<vector<int>> mat(n, vector<int>(n));

    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
    for(auto it:mat){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}



//BRUTE  for(int i=0;i<n;i++){for(int j=0;j<n;j++){ans[j][n-1-i]=mat[i][j];}}    in brute force we use an extra matrix
//but in optimal we are doing it in place