#include<iostream>
#include<stack>
using namespace std;

class MinStack {

    stack<long long> st;
    long long mini;

public:

    void push(int val) {

        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else {

            if(val >= mini) {
                st.push(val);
            }
            else {

                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop() {

        if(st.empty())
            return;

        long long el = st.top();
        st.pop();

        if(el < mini) {

            mini = 2LL * mini - el;
        }
    }

    int top() {

        if(st.empty())
            return -1;

        long long el = st.top();

        if(el < mini)
            return mini;

        return el;
    }

    int getMin() {

        if(st.empty())
            return -1;

        return mini;
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << st.getMin() << endl; // 2

    st.pop();

    cout << st.getMin() << endl; // 3

    cout << st.top() << endl; // 7
}

/*using pair
#include<iostream>
#include<stack>
using namespace std;

class MinStack {

    stack<pair<int,int>> st;

public:

    void push(int val) {

        if(st.empty()) {
            st.push({val, val});
        }
        else {

            int mini = min(val, st.top().second);

            st.push({val, mini});
        }
    }

    void pop() {

        if(st.empty())
            return;

        st.pop();
    }

    int top() {

        if(st.empty())
            return -1;

        return st.top().first;
    }

    int getMin() {

        if(st.empty())
            return -1;

        return st.top().second;
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << st.getMin() << endl; // 2

    st.pop();

    cout << st.getMin() << endl; // 3

    cout << st.top() << endl; // 7
}*/

/*using 2 stacks
#include<iostream>
#include<stack>
using namespace std;

class MinStack {

    stack<int> st;
    stack<int> minSt;

public:

    void push(int val) {

        st.push(val);

        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {

        if(st.empty())
            return;

        if(st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {

        if(st.empty())
            return -1;

        return st.top();
    }

    int getMin() {

        if(minSt.empty())
            return -1;

        return minSt.top();
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << st.getMin() << endl; // 2

    st.pop();

    cout << st.getMin() << endl; // 3

    cout << st.top() << endl; // 7
}*/