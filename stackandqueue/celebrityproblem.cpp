#include<iostream>
#include<vector>
using namespace std;
int celeb(vector<vector<int>>& mat){
    int n=mat[0].size();
    int top=0;
    int down=n-1;
    while(top<down){
        if(mat[top][down]==1)
        top++;
        else 
        down--;
    }
    int candidate=top;
    for(int k=0;k<n;k++){
        if(candidate==k)
        continue;
        if(mat[candidate][k]==1)
        return -1;
        if(mat[k][candidate]==0)
        return -1;
    }
    return candidate;
}
int main(){
    vector<vector<int>> arr={{0,1,1,0},{0,0,0,0},{0,1,0,0},{1,1,0,0}};
    cout<<celeb(arr);

}
//TC-O(N)
//SC-O(1)

//BRUTE FORCE
/*#include<iostream>
#include<vector>
using namespace std;
int celeb(vector<vector<int>>& mat){
    int n=mat[0].size();
    int knowsMe[n]={0};
    int IKnow[n]={0};
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    if(mat[i][j]==1){
        KnowsMe[j]++;
        IKnow[i]++;
    }
    for(i=0;i<n;i++)
    {
    if(KnowsMe[i]==n-1 && IKnow[i]==0)
    return i;}
    return -1;
    }
    }
    */
   //TC-O(N^2)+O(N)
   //SC-O(2N)