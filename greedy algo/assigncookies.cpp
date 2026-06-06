#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter number of children";
    cin>>m;
    cout<<"Enter number of cookies";
    cin>>n;
    int greed[m],size[n];
    cout<<"Enter the greed of each children";
    for(int i=0;i<m;i++)
    cin>>greed[i];
    cout<<"Enter the size of each cookie";
    for(int i=0;i<n;i++)
    cin>>size[i];
    sort(greed, greed + m);
    sort(size, size + n);
    int l=0,r=0;
    while(l<n && r<m){
        if(greed[r]<=size[l])
        r++;
        l++;
    }
    cout<<"Maximum number of children whose greed can be satisfied="<<r;
    return 0;
}

//time complexity- O(nlogn+mlogm+m+n)
//space complexity- O(1)