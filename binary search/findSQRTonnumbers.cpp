#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number whose square root is to be found"<<endl;
    cin>>n;
    int low=1;
    int high=n;
    int ans=1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"Sqrt is "<<ans<<endl;
    return 0;
}
    
//one method is to do it using math function sqrt
//another brute force method is for(int i=1;i<=n;i++){  if(i*i<=n){  ans=i;  }else break;  }