//OPTIMAL
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows in matrix"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int cnt=0;
    int longest=1;
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                cnt++;
                x=x+1;
            }
            longest=max(longest,cnt);
        }
    }
    cout<<"Longest consecutive sequence="<<longest<<endl;
}


//BETTER
/*#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows in matrix"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int longest=1;
    int cnt=0;
    int lastSmaller=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]-1==lastSmaller){
            cnt+=1;
            lastSmaller=arr[i];
        }
        else if(arr[i]!=lastSmaller){
            cnt=1;
            lastSmaller=arr[i];
        }
        longest=max(longest,cnt);
    }
    cout<<"Longest consecutive sequence="<<longest;
}*/

//BRUTE
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool linearSearch(int arr[],int n,int el){
    for(int i=0;i<n;i++){
        if(el==arr[i])
        return true;
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter the number of rows in matrix"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int longest=1;
    for(int i=0;i<n;i++){
        int x=arr[i];
        int count=1;
        while(linearSearch(arr,n,x+1)==true){
            x=x+1;
            count++;
        }
        longest=max(longest,count);
    }
    cout<<"Longest consecutive sequence="<<longest<<endl;
}*/