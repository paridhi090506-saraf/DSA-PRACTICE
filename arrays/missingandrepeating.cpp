//XOR METHOD
/*#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int xr = 0;

    for(int i = 0; i < n; i++) {
        xr ^= arr[i];
        xr ^= (i + 1);
    }

    int bitNo = (xr & ~(xr - 1));

    int zero = 0, one = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] & bitNo)
            one ^= arr[i];
        else
            zero ^= arr[i];

        if((i + 1) & bitNo)
            one ^= (i + 1);
        else
            zero ^= (i + 1);
    }

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == zero)
            cnt++;
    }

    if(cnt == 2)
        cout << "Repeating Number = " << zero
             << "\nMissing Number = " << one;
    else
        cout << "Repeating Number = " << one
             << "\nMissing Number = " << zero;

    return 0;
}*/

//OPTIMAL
/*#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long SN = (long long)n * (n + 1) / 2;
    long long S2N = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long S = 0;
    long long S2 = 0;

    for(int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * arr[i];
    }

    long long val1 = S - SN;          // x - y
    long long val2 = S2 - S2N;        // x² - y²

    val2 = val2 / val1;               // x + y

    long long x = (val1 + val2) / 2; // repeating
    long long y = x - val1;          // missing

    cout << "Repeating Number = " << x << endl;
    cout << "Missing Number = " << y << endl;

    return 0;
}*/



//BETTER
/*#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> hash(n + 1, 0);

    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    int missing = -1, repeating = -1;

    for(int i = 1; i <= n; i++) {
        if(hash[i] == 2)
            repeating = i;

        if(hash[i] == 0)
            missing = i;
    }

    cout << "Repeating Number = " << repeating << endl;
    cout << "Missing Number = " << missing << endl;

    return 0;
}*/



//BRUTE
/*#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int missing = -1, repeating = -1;

    for(int i = 1; i <= n; i++) {
        int cnt = 0;

        for(int j = 0; j < n; j++) {
            if(arr[j] == i)
                cnt++;
        }

        if(cnt == 2)
            repeating = i;
        else if(cnt == 0)
            missing = i;
    }

    cout << "Repeating Number = " << repeating << endl;
    cout << "Missing Number = " << missing << endl;

    return 0;
}*/