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
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])
        continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && arr[j]==arr[j-1])
            continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                int sum=arr[i]+arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum<target)
                k++;
                else if(sum>target)
                l--;
                else{
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])
                    k++;
                    while(k<l && arr[l]==arr[l+1])
                    l--;
                }
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
    cout<<"Enter target"<<endl;
    cin>>target;
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum=arr[i]+arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum==target)
                    {
                        vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
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
    cout<<"Enter target"<<endl;
    cin>>target;
    set<vector<int>> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long> hashSet;
            for(int k=j+1;k<n;k++){
                long long sum=arr[i]+arr[j];
                sum+=arr[k];
                long long fourth=target-sum;
                if(hashSet.find(fourth)!=hashSet.end()){
                    vector<int> temp={arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
                hashSet.insert(arr[k]);
            }
        }
    }
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}*/