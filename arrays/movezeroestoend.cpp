//OPTIMAL
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j == -1) {

        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";

        return 0;
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
//TC-O(N)
//SC-O(1)



/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int j=0,i=0;
    while(j<n)
    {
        if(arr[j]!=0)
        arr[i++]=arr[j];
        j++;
    }
    for(int k=i;k<n;k++)
    arr[k]=0;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}*/
/*BRUTE
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0)
        temp.push_back(arr[i]);
    }
    int s=temp.size();
    for(int i=0;i<s;i++){
        arr[i]=temp[i];
    }
    for(int i=s;i<n;i++)
    arr[i]=0;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
//TC-O(2N)
//SC-O(N)
*/
