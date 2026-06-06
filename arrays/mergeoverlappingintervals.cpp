//OPTIMAL
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter intervals:\n";
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    // Sort according to starting time
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || ans.back()[1]<intervals[i][0])
        ans.push_back({intervals[i][0],intervals[i][1]});
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }

    }
    for(auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
}


//BRUTE
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals:\n";
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    // Sort according to starting time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for(int i = 0; i < n; i++) {

        int start = intervals[i][0];
        int end = intervals[i][1];

        // Skip if already merged
        if(!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        for(int j = i + 1; j < n; j++) {

            // Overlapping condition
            if(intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            }
            else {
                break;
            }
        }

        ans.push_back({start, end});
    }

    cout << "\nMerged Intervals:\n";

    for(auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }

    return 0;
}*/
//TC-O(NlogN)+O(2N)