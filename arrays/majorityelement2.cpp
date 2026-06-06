//optimal
//MOORE'S VOTING ALGORITHM
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
    int count1=0,count2=0;
    int el1=-1,el2=-1;
    for(int i=0;i<n;i++){
        if(count1==0 && arr[i]!=el2){
            count1=1;
            el1=arr[i];
        }
        else if(count2==0 && el1!=arr[i]){
            count2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1)
        count1++;
        else if(arr[i]==el2)
        count2++;
        else{
            count1--;
            count2--;
        }
    }
    count1=0,count2=0;
    vector<int> ls;
    for(int i=0;i<n;i++){
        if(el1==arr[i])
        count1++;
        if(el2==arr[i])
        count2++;
    }
    int mini=(int)(n/3)+1;
    if(count1>=mini)
    ls.push_back(el1);
    if(count2>=mini){
        ls.push_back(el2);
    }
    for(auto it:ls)
    cout<<it<<" ";
}



//Brute
/*#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements" << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ls;

    for(int i = 0; i < n; i++){

        // if already present, skip
        if(ls.size() == 0 || ls[0] != arr[i]){

            int cnt = 0;

            for(int j = 0; j < n; j++){

                if(arr[j] == arr[i])
                    cnt++;
            }

            if(cnt > n/3)
                ls.push_back(arr[i]);
        }

        if(ls.size() == 2)
            break;
    }

    for(auto it : ls)
        cout << it << " ";
}
*/

//BETTER
/*#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){

    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements" << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    map<int,int> mpp;

    vector<int> ls;

    int mini = (n/3) + 1;

    for(int i = 0; i < n; i++){

        mpp[arr[i]]++;

        if(mpp[arr[i]] == mini){

            ls.push_back(arr[i]);
        }

        if(ls.size() == 2)
            break;
    }

    for(auto it : ls)
        cout << it << " ";
}*/
    