#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool checkValidString(string s){

    int mini = 0;
    int maxi = 0;

    for(char ch : s){

        if(ch == '('){
            mini++;
            maxi++;
        }

        else if(ch == ')'){
            mini--;
            maxi--;
        }

        else{ // '*'
            mini--;
            maxi++;
        }

        // too many closing brackets
        if(maxi < 0)
            return false;

        // mini should never be negative
        mini = max(mini, 0);
    }

    return mini == 0;
}

int main(){

    string s;

    cin >> s;

    if(checkValidString(s))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}

//TC-O(N)
//SC-O(1)
//Can be done using recursion(tc-O(3^n)) or dynamic programming(tc-O(n^2))