#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

string newStr(string s, int k){

    stack<char> st;

    for(int i = 0; i < s.length(); i++){

        while(!st.empty() && k > 0 && st.top() > s[i]){

            st.pop();
            k--;
        }

        st.push(s[i]);
    }

    // If k still remains
    while(k > 0 && !st.empty()){

        st.pop();
        k--;
    }
    if(st.empty())
    return "0";

    string res = "";

    // Store in reverse order
    while(!st.empty()){

        res += st.top();
        st.pop();
    }
    
/*
    // Reverse to get correct order
    reverse(res.begin(), res.end());

    // Remove leading zeros
    while(res.length() > 0 &&
          res.front() == '0'){

        res.erase(res.begin());
    }
*/
    //we can also do after storing in reverse order
    while(res.length() > 0 && res.back() == '0'){
        res.pop_back();
    }
        //and then reverse
    reverse(res.begin(),res.end());    
    

    // If empty after removing zeros
    if(res.empty())
        return "0";

    return res;
}

int main(){

    string s = "10200";

    int k = 1;

    cout << newStr(s, k);

    return 0;
}

//monostack increasing