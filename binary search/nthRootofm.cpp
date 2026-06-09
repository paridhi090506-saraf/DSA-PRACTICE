#include <iostream>
using namespace std;
int power(int mid, int n, int m) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= mid;
        if(ans > m)
            return 2; // greater than m
    }
    if(ans == m)
        return 1; // equal to m
    return 0; // less than m
}
int main() {
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    int low = 1;
    int high = m;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int val = power(mid, n, m);
        if(val == 1) {
            cout << "Nth root is: " << mid << endl;
            return 0;
        }
        else if(val == 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << -1 << endl;
    return 0;
}