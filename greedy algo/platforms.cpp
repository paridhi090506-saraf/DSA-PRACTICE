#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int timings(vector<int> &arr, vector<int> &dep)
{
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int platforms=0,j=0,maxcount=0,i=0;
    while(i<arr.size())
    {
        if(arr[i]<=dep[j]){
        platforms++;
        i++;
        }
        else{
            platforms--;
            j=j+1;
        }
        maxcount=max(maxcount,platforms);
    }
    return maxcount;
}
int main(){
    vector<int> arr={900,945,955,1100,1500,1800};
    vector<int> dep={920,1200,1130,1150,1900,2000};
    int c=timings(arr,dep);
    cout<<c;
    return 0;
}

//TC- O(2(NlogN+N))
//SC- O(1)