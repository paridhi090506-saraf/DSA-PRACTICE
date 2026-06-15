#include <iostream>
#include <vector>
#include <climits>
using namespace std;
double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    if (n1 > n2)
        return findMedianSortedArrays(arr2, arr1);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    while (low <= high) {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;
        int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? arr1[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? arr2[mid2] : INT_MAX;
        if (l1 <= r2 && l2 <= r1) {
            // Correct partition found
            if ((n1 + n2) % 2 == 1)
                return max(l1, l2);
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2) {
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }
    return 0.0; // Should never reach here
}
int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> arr1(n), arr2(m);
    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    cout << "Median = " << findMedianSortedArrays(arr1, arr2);
    return 0;
}


/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of elements in 1st array"<<endl;
    cin>>n;
    cout<<"Enter the number of elements in 2nd array"<<endl;
    cin>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    cout<<"Enter the elements of array 1"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the elements of array 2"<<endl;
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int i=0,j=0;
    int count=0;
    int ind2=(n+m)/2;
    int ind1=ind2-1;
    int el1=-1,el2=-1;
    while(i<n && j<m && count<=ind2){
        if(arr1[i]<arr2[j]){
            if(count==ind1) el1=arr1[i];
            if(count==ind2) el2=arr1[i];
            count++;
            i++;
        }
        else{
            if(count==ind1) el1=arr2[j];
            if(count==ind2) el2=arr2[j];
            count++;
            j++;
        }
    }
    while(i<n && count<=ind2){
        if(count==ind1) el1=arr1[i];
        if(count==ind2) el2=arr1[i];
        count++;
        i++;
    }
    while(j<m && count<=ind2){
        if(count==ind1) el1=arr2[j];
        if(count==ind2) el2=arr2[j];
        count++;
        j++;
    }
    if((n+m)%2==0){
        double median=(double)(el1+el2)/2.0;
        cout<<"Median of 2 sorted arrays="<<median<<endl;
        return 0;
    }
    cout<<"Median of 2 sorted arrays="<<el2<<endl;
}*/

/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of elements in 1st array"<<endl;
    cin>>n;
    cout<<"Enter the number of elements in 2nd array"<<endl;
    cin>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    cout<<"Enter the elements of array 1"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the elements of array 2"<<endl;
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    vector<int> arr3;
    int i=0,j=0;
    int ind2=(n+m)/2;
    int ind1=ind2-1;
    int el1=-1,el2=-1;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        arr3.push_back(arr2[j]);
        j++;
    }
    if((n+m)%2==0){
        el1=arr3[ind1];
        el2=arr3[ind2];
        double median=(double)(el1+el2)/2.0;
        cout<<"Median of 2 sorted arrays="<<median<<endl;
        return 0;
    }
    cout<<"Median of 2 sorted arrays="<<arr3[ind2]<<endl;
}*/
