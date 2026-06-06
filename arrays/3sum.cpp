//OPTIMAL
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])
        continue;
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0)//because here target is zero
            j++;
            else if(sum>0)
            k--;
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])
                j++;
                while(j<k && arr[k]==arr[k+1])
                k--;
            }
        }
    }
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}






//BETTER
/*#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int target;
    cout<<"Enter the target";
    cin>>target;
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashSet;
        for(int j=i+1;j<n;j++){
            int third=target-(arr[i]+arr[j]);
            if(hashSet.find(third)!=hashSet.end()){
                vector<int> temp={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
*/

//BRUTE
/*#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int target;
    cout<<"Enter the target";
    cin>>target;
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vector<int> temp;
            for(int k=j+1;k<n;k++){
            if(arr[i]+arr[j]+arr[k]==target){
                vector<int> temp = {arr[i], arr[j], arr[k]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
                }
            }
        }
    }
    for(auto it:st){
        for(auto ele:it){
        cout<<ele<<" ";
    }
    cout<<endl;
}
}*/