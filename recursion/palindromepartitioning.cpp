#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void solve(int index, string s, vector<string> &path, vector<vector<string>> &ans) {

    // If we've reached the end, store one partition
    if (index == s.size()) {
        ans.push_back(path);
        return;
    }

    // Try every possible substring starting from 'index'
    for (int i = index; i < s.size(); i++) {

        if (isPalindrome(s, index, i)) {

            path.push_back(s.substr(index, i - index + 1));

            solve(i + 1, s, path, ans);

            // Backtrack
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;

    solve(0, s, path, ans);

    return ans;
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<vector<string>> ans = partition(s);

    cout << "\nPalindrome Partitions:\n";

    for (auto partition : ans) {
        for (auto str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}