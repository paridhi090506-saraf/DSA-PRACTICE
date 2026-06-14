#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int maxOnes = 0;
    int rowIndex = -1;
    for(int i = 0; i < n; i++) {
        int low = 0, high = m - 1;
        int firstOne = m;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[i][mid]>0) {  //get upperbound of 0 so will get index of first 1 in ith row.. we can also do lowerbound of 1
                firstOne = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        int ones = m - firstOne;
        if(ones > maxOnes) {
            maxOnes = ones;
            rowIndex = i;
        }
    }
    cout << "Row with maximum 1s: " << rowIndex << endl;
    return 0;
}

//for brute force sum up the elements of each row.. the row having max sum will be returned